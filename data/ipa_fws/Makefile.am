# Firmware hardware addresses
# If these differ across devices, define them accordingly.
DPS_ADDR := 0x07B5e000
HPS_ADDR := 0x07B5e080
GSI_ADDR := 0x07B08000
GSI_MEM_SIZE = 0x4000

# californium IPA FWs configs (IPAv3.0)
if IS_MDMCALIFORNIUM
GSI_FW_FILE := fw_mhi_ipa_v3.bin
TARGET_NAME := mdmcalifornium
endif # californium check

# hedgehog IPA FWs configs (IPAv3.5)
if IS_SDXHEDGEHOG
GSI_FW_FILE := fw_mhi_ipa_v3.5.bin
TARGET_NAME := sdxhedgehog
endif # hedgehog check

all:
	@echo IPA FW creation for $(TARGET_NAME)
	python elf_creator.py \
	--gsi_fw $(GSI_FW_FILE) \
	--gsi_fw_address $(GSI_ADDR) \
	--gsi_fw_mem_size $(GSI_MEM_SIZE) \
	--hps hps.bin \
	--hps_addr $(HPS_ADDR) \
	--dps dps.bin \
	--dps_addr $(DPS_ADDR) \
	--outfile ipa_fws.elf
clean:
	rm ipa_fws.*
