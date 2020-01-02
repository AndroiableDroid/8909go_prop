/*
 * Copyright (c) 2015 Qualcomm Technologies, Inc.
 * All Rights Reserved.
 * Confidential and Proprietary - Qualcomm Technologies, Inc.
 */

#define LOG_TAG "Iris_parser"
#include <utils/Log.h>

#include "iris_parser.h"
#include "iris_common.h"
#include "iris_manager.h"
#include "qcosal.h"

int iris_req_init(struct iris_request *req, void *buf, uint32_t len)
{
    if (!buf || len < sizeof(uint32_t))
        return ERROR_INVL;

    req->buf = buf;
    req->len = len;
    req->index = 0;
    return 0;
}

void iris_req_deinit(struct iris_request *req)
{
    (void)req;
}

int iris_req_get_uint8(struct iris_request *req, uint8_t *val)
{
    if (req->index + sizeof(uint8_t) > req->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY(val, (char *)req->buf + req->index, sizeof(uint8_t));
    req->index += sizeof(uint8_t);
    return 0;
}

int iris_req_get_uint32(struct iris_request *req, uint32_t *val)
{
    if (req->index + sizeof(uint32_t) > req->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY(val, (char *)req->buf + req->index, sizeof(uint32_t));
    req->index += sizeof(uint32_t);
    return 0;
}

int iris_req_get_uint64(struct iris_request *req, uint64_t *val)
{
    if (req->index + sizeof(uint64_t) > req->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY(val, (char *)req->buf + req->index, sizeof(uint64_t));
    req->index += sizeof(uint64_t);
    return 0;
}

int iris_req_get_string(struct iris_request *req, unsigned char **val)
{
    int ret;
    uint32_t str_len;

    *val = NULL;

    ret = iris_req_get_uint32(req, &str_len);
    if (ret)
        return ret;

    if (!str_len || req->index + str_len > req->len)
        return ERROR_INVL;

    *val = (unsigned char *)req->buf + req->index;
    req->index += str_len;
    return 0;
}

int iris_req_get_data(struct iris_request *req, void *data, uint32_t *len)
{
    int ret;
    uint32_t data_len = 0;

    ret = iris_req_get_uint32(req, &data_len);
    if (ret) {
        IRIS_OSAL_LOG_CRITICAL("iris_req_get_uint32 failed %dx\n", ret);
        return ret;
    }

    if (req->index + data_len > req->len) {
        IRIS_OSAL_LOG_CRITICAL("Size doesn't match: req index = %d data_len=%d, req len = %d\n",
                                req->index, data_len, req->len);
        return ERROR_INVL;
    }

    if (data_len > 0)
        IRIS_OSAL_MEMCPY(data, (char *)req->buf + req->index, data_len);
    *len = data_len;
    req->index += data_len;
    return 0;
}

int iris_req_get_struct(struct iris_request *req, void *data, uint32_t len)
{
    if (req->index + len > req->len) {
        IRIS_OSAL_LOG_CRITICAL("Size overflow: req index = %d req len = %d len = %d\n",
                                req->index, req->len, len);
        return ERROR_INVL;
    }

    IRIS_OSAL_MEMCPY(data, (char *)req->buf + req->index, len);
    req->index += len;
    return 0;
}


int iris_req_get_token(struct iris_request *req, struct hw_auth_token *token)
{
    int ret = 0;
    uint32_t hmac_size = sizeof(token->hmac);
    ret |= iris_req_get_uint8(req, &token->version);
    ret |= iris_req_get_uint64(req, &token->challenge);
    ret |= iris_req_get_uint64(req, &token->user_id);
    ret |= iris_req_get_uint64(req, &token->authenticator_id);
    ret |= iris_req_get_uint32(req, &token->authenticator_type);
    ret |= iris_req_get_uint64(req, &token->timestamp);
    ret |= iris_req_get_data(req, &token->hmac[0], &hmac_size);
    if (hmac_size != sizeof(token->hmac)) {
        IRIS_OSAL_LOG_CRITICAL("hmac size incorrect %d %d", hmac_size, sizeof(token->hmac));
    }
    return ret;
}



int iris_response_init(struct iris_response *response, void *buf, uint32_t len)
{
    if (!buf || len < sizeof(uint32_t))
        return ERROR_INVL;

    response->buf = buf;
    response->len = len;
    response->index = 0;
    return 0;
}

void iris_response_deinit(struct iris_response *response)
{
    (void)response;
}

int iris_response_put_int32(struct iris_response *response, int32_t val)
{
    if (response->index + sizeof(int32_t) > response->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY((char *)response->buf + response->index, &val, sizeof(int32_t));
    response->index += sizeof(int32_t);
    return 0;
}

int iris_response_put_uint32(struct iris_response *response, uint32_t val)
{
    if (response->index + sizeof(uint32_t) > response->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY((char *)response->buf + response->index, &val, sizeof(uint32_t));
    response->index += sizeof(uint32_t);
    return 0;
}

int iris_response_put_string(struct iris_response *response, unsigned char *str)
{
    int ret;
    uint32_t str_len = iris_osal_strlen((char *)str) + 1;

    ret = iris_response_put_uint32(response, str_len);
    if (ret)
        return ret;

    if (response->index + str_len > response->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY((char *)response->buf + response->index, str, str_len);
    response->index += str_len;
    return 0;

}

int iris_response_put_uint8(struct iris_response *response, uint8_t val)
{
    if (response->index + sizeof(uint8_t) > response->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY((char *)response->buf + response->index, &val, sizeof(uint8_t));
    response->index += sizeof(uint8_t);
    return 0;
}

int iris_response_put_uint64(struct iris_response *response, uint64_t val)
{
    if (response->index + sizeof(uint64_t) > response->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY((char *)response->buf + response->index, &val, sizeof(uint64_t));
    response->index += sizeof(uint64_t);
    return 0;
}

int iris_response_put_data(struct iris_response *response, void *data, uint32_t len)
{
    int ret;

    ret = iris_response_put_uint32(response, len);
    if (ret)
        return ret;

    if (response->index + len > response->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY((char *)response->buf + response->index, data, len);
    response->index += len;
    return 0;
}

int iris_response_put_struct(struct iris_response *response, void *data, uint32_t len)
{
    if (response->index + len > response->len)
        return ERROR_INVL;

    IRIS_OSAL_MEMCPY((char *)response->buf + response->index, data, len);
    response->index += len;
    return 0;
}

int iris_response_put_token(struct iris_response *response, struct hw_auth_token *token)
{
    int ret;

    ret = iris_response_put_uint8(response, token->version);
    if (ret)
        return ret;

    ret = iris_response_put_uint64(response, token->challenge);
    if (ret)
        return ret;

    ret = iris_response_put_uint64(response, token->user_id);
    if (ret)
        return ret;

    ret = iris_response_put_uint64(response, token->authenticator_id);
    if (ret)
        return ret;

    ret = iris_response_put_uint32(response, token->authenticator_type);
    if (ret)
        return ret;

    ret = iris_response_put_uint64(response, token->timestamp);
    if (ret)
        return ret;

    ret = iris_response_put_data(response, token->hmac, sizeof(token->hmac));

    return ret;
}


