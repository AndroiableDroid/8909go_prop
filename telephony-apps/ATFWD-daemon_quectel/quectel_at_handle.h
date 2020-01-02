/********************************************************************************
 *      Copyright:  (C) 2019 quectel
 *                  All rights reserved.
 *
 *       Filename:  quectel_at_quectel.h
 *    Description:  This is head of quectel_at_quectel.cpp file. 
 *
 *        Version:  1.0.0(2019年03月19日)
 *         Author:  Peeta Chen <peeta.chen@quectel.com>
 *      ChangeLog:  1, Release initial version on "2019年03月19日 14时41分32秒"
 *                 
 ********************************************************************************/
#ifndef __QUECTEL_AT_QUECTEL_H__
#define __QUECTEL_AT_QUECTEL_H__

#include "AtCmdFwd.h"

#ifdef __cplusplus
extern "C" {
#endif

#define QUECTEL_QGMR_CMD
#define QUECTEL_QAPSUB_CMD  // abb by ben 20180710
#define QUECTEL_QDEVINFO_CMD
#define QUECTEL_QAPCMD_CMD

void quec_qgmr_handle(const AtCmd *cmd, AtCmdResponse *response);
void quec_qapsub_handle(const AtCmd *cmd, AtCmdResponse *response);
void quec_qdevinfo_handle(const AtCmd *cmd, AtCmdResponse *response);
void quec_qapcmd_handle(const AtCmd *cmd, AtCmdResponse *response);

#ifdef __cplusplus
}
#endif

#endif /* __QUECTEL_AT_QUECTEL_H__ */

