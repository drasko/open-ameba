#ifndef __INC_RTL8195A_SYS_ON_BIT_H
#define __INC_RTL8195A_SYS_ON_BIT_H

#define HAL_SYS_CTRL_READ32(addr)            HAL_READ32(SYSTEM_CTRL_BASE, addr)
#define HAL_SYS_CTRL_WRITE32(addr, value)    HAL_WRITE32(SYSTEM_CTRL_BASE, addr, value)

#define CPU_OPT_WIDTH 0x1F

//2 REG_NOT_VALID

//2 REG_SYS_PWR_CTRL

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID
#define BIT_SYS_PWR_SOC_EN BIT(2)
#define BIT_SYS_PWR_RET_MEM_EN BIT(1)
#define BIT_SYS_PWR_PEON_EN BIT(0)

//2 REG_SYS_ISO_CTRL

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID
#define BIT_SYS_ISO_SYSPLL BIT(7)

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID
#define BIT_SYS_ISO_SOC BIT(2)
#define BIT_SYS_ISO_RET_MEM BIT(1)
#define BIT_SYS_ISO_PEON BIT(0)

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_SYS_FUNC_EN
#define BIT_SYS_AMACRO_EN BIT(31)
#define BIT_SYS_PWRON_TRAP_SHTDN_N BIT(30)
#define BIT_SYS_FEN_SIC_MST BIT(25)
#define BIT_SYS_FEN_SIC BIT(24)

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID
#define BIT_SOC_SYSPEON_EN BIT(4)

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID
#define BIT_SYS_FEN_EELDR BIT(0)

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_SYS_CLK_CTRL0

//2 REG_NOT_VALID
#define BIT_SOC_OCP_IOBUS_CK_EN BIT(2)
#define BIT_SYSON_CK_EELDR_EN BIT(1)
#define BIT_SYSON_CK_SYSREG_EN BIT(0)

//2 REG_SYS_CLK_CTRL1

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

#define BIT_SHIFT_PESOC_OCP_CPU_CK_SEL 4
#define BIT_MASK_PESOC_OCP_CPU_CK_SEL 0x7
#define BIT_PESOC_OCP_CPU_CK_SEL(x) (((x) & BIT_MASK_PESOC_OCP_CPU_CK_SEL) << BIT_SHIFT_PESOC_OCP_CPU_CK_SEL)


//2 REG_NOT_VALID
#define BIT_PESOC_EELDR_CK_SEL BIT(0)

//2 REG_SYS_SWR_CTRL3

//2 REG_RSV_CTRL

//2 REG_RF_CTRL

//2 REG_SYS_EFUSE_SYSCFG0

#define BIT_SHIFT_SYS_EEROM_SWR_PAR_05_00 24
#define BIT_MASK_SYS_EEROM_SWR_PAR_05_00 0x3f
#define BIT_SYS_EEROM_SWR_PAR_05_00(x) (((x) & BIT_MASK_SYS_EEROM_SWR_PAR_05_00) << BIT_SHIFT_SYS_EEROM_SWR_PAR_05_00)


#define BIT_SHIFT_SYS_EEROM_LDO_PAR_07_04 20
#define BIT_MASK_SYS_EEROM_LDO_PAR_07_04 0xf
#define BIT_SYS_EEROM_LDO_PAR_07_04(x) (((x) & BIT_MASK_SYS_EEROM_LDO_PAR_07_04) << BIT_SHIFT_SYS_EEROM_LDO_PAR_07_04)

#define BIT_SYS_CHIPPDN_EN BIT(17)
#define BIT_SYS_EEROM_B12V_EN BIT(16)

#define BIT_SHIFT_SYS_EEROM_VID1 8
#define BIT_MASK_SYS_EEROM_VID1 0xff
#define BIT_SYS_EEROM_VID1(x) (((x) & BIT_MASK_SYS_EEROM_VID1) << BIT_SHIFT_SYS_EEROM_VID1)


#define BIT_SHIFT_SYS_EEROM_VID0 0
#define BIT_MASK_SYS_EEROM_VID0 0xff
#define BIT_SYS_EEROM_VID0(x) (((x) & BIT_MASK_SYS_EEROM_VID0) << BIT_SHIFT_SYS_EEROM_VID0)


//2 REG_SYS_EFUSE_SYSCFG1

#define BIT_SHIFT_SYS_PDSPL_STL 24
#define BIT_MASK_SYS_PDSPL_STL 0x3
#define BIT_SYS_PDSPL_STL(x) (((x) & BIT_MASK_SYS_PDSPL_STL) << BIT_SHIFT_SYS_PDSPL_STL)


#define BIT_SHIFT_SYS_PDSOC_STL 22
#define BIT_MASK_SYS_PDSOC_STL 0x3
#define BIT_SYS_PDSOC_STL(x) (((x) & BIT_MASK_SYS_PDSOC_STL) << BIT_SHIFT_SYS_PDSOC_STL)


#define BIT_SHIFT_SYS_PDPON_STL 20
#define BIT_MASK_SYS_PDPON_STL 0x3
#define BIT_SYS_PDPON_STL(x) (((x) & BIT_MASK_SYS_PDPON_STL) << BIT_SHIFT_SYS_PDPON_STL)


#define BIT_SHIFT_SYS_SWREG_XRT 18
#define BIT_MASK_SYS_SWREG_XRT 0x3
#define BIT_SYS_SWREG_XRT(x) (((x) & BIT_MASK_SYS_SWREG_XRT) << BIT_SHIFT_SYS_SWREG_XRT)


#define BIT_SHIFT_SYS_SWSLC_STL 16
#define BIT_MASK_SYS_SWSLC_STL 0x3
#define BIT_SYS_SWSLC_STL(x) (((x) & BIT_MASK_SYS_SWSLC_STL) << BIT_SHIFT_SYS_SWSLC_STL)


#define BIT_SHIFT_SYS_EEROM_SWR_PAR_46_45 14
#define BIT_MASK_SYS_EEROM_SWR_PAR_46_45 0x3
#define BIT_SYS_EEROM_SWR_PAR_46_45(x) (((x) & BIT_MASK_SYS_EEROM_SWR_PAR_46_45) << BIT_SHIFT_SYS_EEROM_SWR_PAR_46_45)


#define BIT_SHIFT_SYS_EEROM_SWR_PAR_40_39 12
#define BIT_MASK_SYS_EEROM_SWR_PAR_40_39 0x3
#define BIT_SYS_EEROM_SWR_PAR_40_39(x) (((x) & BIT_MASK_SYS_EEROM_SWR_PAR_40_39) << BIT_SHIFT_SYS_EEROM_SWR_PAR_40_39)


#define BIT_SHIFT_SYS_EEROM_SWR_PAR_33_26 4
#define BIT_MASK_SYS_EEROM_SWR_PAR_33_26 0xff
#define BIT_SYS_EEROM_SWR_PAR_33_26(x) (((x) & BIT_MASK_SYS_EEROM_SWR_PAR_33_26) << BIT_SHIFT_SYS_EEROM_SWR_PAR_33_26)


#define BIT_SHIFT_SYS_EEROM_SWSLD_VOL 0
#define BIT_MASK_SYS_EEROM_SWSLD_VOL 0x7
#define BIT_SYS_EEROM_SWSLD_VOL(x) (((x) & BIT_MASK_SYS_EEROM_SWSLD_VOL) << BIT_SHIFT_SYS_EEROM_SWSLD_VOL)


//2 REG_SYS_EFUSE_SYSCFG2

#define BIT_SHIFT_SYS_EERROM_ANAPAR_SPLL_24_15 21
#define BIT_MASK_SYS_EERROM_ANAPAR_SPLL_24_15 0x3ff
#define BIT_SYS_EERROM_ANAPAR_SPLL_24_15(x) (((x) & BIT_MASK_SYS_EERROM_ANAPAR_SPLL_24_15) << BIT_SHIFT_SYS_EERROM_ANAPAR_SPLL_24_15)


#define BIT_SHIFT_SYS_EEROM_ANAPAR_SPLL_05_02 16
#define BIT_MASK_SYS_EEROM_ANAPAR_SPLL_05_02 0xf
#define BIT_SYS_EEROM_ANAPAR_SPLL_05_02(x) (((x) & BIT_MASK_SYS_EEROM_ANAPAR_SPLL_05_02) << BIT_SHIFT_SYS_EEROM_ANAPAR_SPLL_05_02)


#define BIT_SHIFT_SYS_EEROM_XTAL_STEL_SEL 12
#define BIT_MASK_SYS_EEROM_XTAL_STEL_SEL 0x3
#define BIT_SYS_EEROM_XTAL_STEL_SEL(x) (((x) & BIT_MASK_SYS_EEROM_XTAL_STEL_SEL) << BIT_SHIFT_SYS_EEROM_XTAL_STEL_SEL)


#define BIT_SHIFT_SYS_EEROM_XTAL_FREQ_SEL 8
#define BIT_MASK_SYS_EEROM_XTAL_FREQ_SEL 0xf
#define BIT_SYS_EEROM_XTAL_FREQ_SEL(x) (((x) & BIT_MASK_SYS_EEROM_XTAL_FREQ_SEL) << BIT_SHIFT_SYS_EEROM_XTAL_FREQ_SEL)


//2 REG_SYS_EFUSE_SYSCFG3

#define BIT_SHIFT_SYS_DBG_PINGP_EN 28
#define BIT_MASK_SYS_DBG_PINGP_EN 0xf
#define BIT_SYS_DBG_PINGP_EN(x) (((x) & BIT_MASK_SYS_DBG_PINGP_EN) << BIT_SHIFT_SYS_DBG_PINGP_EN)


#define BIT_SHIFT_SYS_DBG_SEL 16
#define BIT_MASK_SYS_DBG_SEL 0xfff
#define BIT_SYS_DBG_SEL(x) (((x) & BIT_MASK_SYS_DBG_SEL) << BIT_SHIFT_SYS_DBG_SEL)


#define BIT_SHIFT_SYS_DBGBY3_LOC_SEL 14
#define BIT_MASK_SYS_DBGBY3_LOC_SEL 0x3
#define BIT_SYS_DBGBY3_LOC_SEL(x) (((x) & BIT_MASK_SYS_DBGBY3_LOC_SEL) << BIT_SHIFT_SYS_DBGBY3_LOC_SEL)


#define BIT_SHIFT_SYS_DBGBY2_LOC_SEL 12
#define BIT_MASK_SYS_DBGBY2_LOC_SEL 0x3
#define BIT_SYS_DBGBY2_LOC_SEL(x) (((x) & BIT_MASK_SYS_DBGBY2_LOC_SEL) << BIT_SHIFT_SYS_DBGBY2_LOC_SEL)


#define BIT_SHIFT_SYS_DBGBY1_LOC_SEL 10
#define BIT_MASK_SYS_DBGBY1_LOC_SEL 0x3
#define BIT_SYS_DBGBY1_LOC_SEL(x) (((x) & BIT_MASK_SYS_DBGBY1_LOC_SEL) << BIT_SHIFT_SYS_DBGBY1_LOC_SEL)


#define BIT_SHIFT_SYS_DBGBY0_LOC_SEL 8
#define BIT_MASK_SYS_DBGBY0_LOC_SEL 0x3
#define BIT_SYS_DBGBY0_LOC_SEL(x) (((x) & BIT_MASK_SYS_DBGBY0_LOC_SEL) << BIT_SHIFT_SYS_DBGBY0_LOC_SEL)

#define BIT_SYS_EEROM_ANAPAR_SPLL_49 BIT(3)

#define BIT_SHIFT_SYS_EEROM_ANAPAR_SPLL_27_25 0
#define BIT_MASK_SYS_EEROM_ANAPAR_SPLL_27_25 0x7
#define BIT_SYS_EEROM_ANAPAR_SPLL_27_25(x) (((x) & BIT_MASK_SYS_EEROM_ANAPAR_SPLL_27_25) << BIT_SHIFT_SYS_EEROM_ANAPAR_SPLL_27_25)


//2 REG_SYS_EFUSE_SYSCFG4

#define BIT_SHIFT_SYS_GPIOA_E2 1
#define BIT_MASK_SYS_GPIOA_E2 0x7
#define BIT_SYS_GPIOA_E2(x) (((x) & BIT_MASK_SYS_GPIOA_E2) << BIT_SHIFT_SYS_GPIOA_E2)

#define BIT_SYS_GPIOA_H3L1 BIT(0)

//2 REG_SYS_EFUSE_SYSCFG5

//2 REG_NOT_VALID

//2 REG_SYS_EFUSE_SYSCFG6

#define BIT_SHIFT_SYS_SPIC_INIT_BAUD_RATE_SEL 26
#define BIT_MASK_SYS_SPIC_INIT_BAUD_RATE_SEL 0x3
#define BIT_SYS_SPIC_INIT_BAUD_RATE_SEL(x) (((x) & BIT_MASK_SYS_SPIC_INIT_BAUD_RATE_SEL) << BIT_SHIFT_SYS_SPIC_INIT_BAUD_RATE_SEL)


#define BIT_SHIFT_SYS_CPU_CLK_SEL 24
#define BIT_MASK_SYS_CPU_CLK_SEL 0x3
#define BIT_SYS_CPU_CLK_SEL(x) (((x) & BIT_MASK_SYS_CPU_CLK_SEL) << BIT_SHIFT_SYS_CPU_CLK_SEL)


//2 REG_SYS_EFUSE_SYSCFG7
#define BIT_SYS_MEM_RMV_SIGN BIT(31)
#define BIT_SYS_MEM_RMV_1PRF1 BIT(29)
#define BIT_SYS_MEM_RMV_1PRF0 BIT(28)
#define BIT_SYS_MEM_RMV_1PSR BIT(27)
#define BIT_SYS_MEM_RMV_1PHSR BIT(26)
#define BIT_SYS_MEM_RMV_ROM BIT(25)

#define BIT_SHIFT_SYS_MEM_RME_CPU 22
#define BIT_MASK_SYS_MEM_RME_CPU 0x7
#define BIT_SYS_MEM_RME_CPU(x) (((x) & BIT_MASK_SYS_MEM_RME_CPU) << BIT_SHIFT_SYS_MEM_RME_CPU)


#define BIT_SHIFT_SYS_MEM_RME_WLAN 19
#define BIT_MASK_SYS_MEM_RME_WLAN 0x7
#define BIT_SYS_MEM_RME_WLAN(x) (((x) & BIT_MASK_SYS_MEM_RME_WLAN) << BIT_SHIFT_SYS_MEM_RME_WLAN)

#define BIT_SYS_MEM_RME_USB BIT(18)
#define BIT_SYS_MEM_RME_SDIO BIT(17)

//2 REG_SYS_REGU_CTRL0

#define BIT_SHIFT_SYS_REGU_LDO25M_ADJ 20
#define BIT_MASK_SYS_REGU_LDO25M_ADJ 0xf
#define BIT_SYS_REGU_LDO25M_ADJ(x) (((x) & BIT_MASK_SYS_REGU_LDO25M_ADJ) << BIT_SHIFT_SYS_REGU_LDO25M_ADJ)

#define BIT_SYS_REGU_ANACK_4M_EN BIT(19)
#define BIT_SYS_REGU_ANACK_4M_SEL BIT(18)
#define BIT_SYS_REGU_PC_EF_EN BIT(17)
#define BIT_SYS_REGU_LDOH12_SLP_EN BIT(16)

#define BIT_SHIFT_SYS_REGU_LDOH12_ADJ 12
#define BIT_MASK_SYS_REGU_LDOH12_ADJ 0xf
#define BIT_SYS_REGU_LDOH12_ADJ(x) (((x) & BIT_MASK_SYS_REGU_LDOH12_ADJ) << BIT_SHIFT_SYS_REGU_LDOH12_ADJ)


#define BIT_SHIFT_SYS_REGU_LDO25E_ADJ 8
#define BIT_MASK_SYS_REGU_LDO25E_ADJ 0xf
#define BIT_SYS_REGU_LDO25E_ADJ(x) (((x) & BIT_MASK_SYS_REGU_LDO25E_ADJ) << BIT_SHIFT_SYS_REGU_LDO25E_ADJ)

#define BIT_SYS_REGU_DSLEPM_EN BIT(7)
#define BIT_SYS_REGU_PC_33V_EN BIT(3)
#define BIT_SYS_REGU_PC_EF25_EN BIT(2)
#define BIT_SYS_REGU_LDO25M_EN BIT(1)
#define BIT_SYS_REGU_LDO25E_EN BIT(0)

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_SYS_SWR_CTRL0

#define BIT_SHIFT_SYS_SWR12_COMP_R2 30
#define BIT_MASK_SYS_SWR12_COMP_R2 0x3
#define BIT_SYS_SWR12_COMP_R2(x) (((x) & BIT_MASK_SYS_SWR12_COMP_R2) << BIT_SHIFT_SYS_SWR12_COMP_R2)


#define BIT_SHIFT_SYS_SWR12_COMP_R1 28
#define BIT_MASK_SYS_SWR12_COMP_R1 0x3
#define BIT_SYS_SWR12_COMP_R1(x) (((x) & BIT_MASK_SYS_SWR12_COMP_R1) << BIT_SHIFT_SYS_SWR12_COMP_R1)


#define BIT_SHIFT_SYS_SWR12_COMP_C3 26
#define BIT_MASK_SYS_SWR12_COMP_C3 0x3
#define BIT_SYS_SWR12_COMP_C3(x) (((x) & BIT_MASK_SYS_SWR12_COMP_C3) << BIT_SHIFT_SYS_SWR12_COMP_C3)


#define BIT_SHIFT_SYS_SWR12_COMP_C2 24
#define BIT_MASK_SYS_SWR12_COMP_C2 0x3
#define BIT_SYS_SWR12_COMP_C2(x) (((x) & BIT_MASK_SYS_SWR12_COMP_C2) << BIT_SHIFT_SYS_SWR12_COMP_C2)


#define BIT_SHIFT_SYS_SWR12_COMP_C1 22
#define BIT_MASK_SYS_SWR12_COMP_C1 0x3
#define BIT_SYS_SWR12_COMP_C1(x) (((x) & BIT_MASK_SYS_SWR12_COMP_C1) << BIT_SHIFT_SYS_SWR12_COMP_C1)

#define BIT_SYS_SWR12_COMP_TYPE_L BIT(21)
#define BIT_SYS_SWR12_FPWM_MD BIT(20)

#define BIT_SHIFT_SYS_SPSLDO_VOL 17
#define BIT_MASK_SYS_SPSLDO_VOL 0x7
#define BIT_SYS_SPSLDO_VOL(x) (((x) & BIT_MASK_SYS_SPSLDO_VOL) << BIT_SHIFT_SYS_SPSLDO_VOL)


#define BIT_SHIFT_SYS_SWR12_IN 14
#define BIT_MASK_SYS_SWR12_IN 0x7
#define BIT_SYS_SWR12_IN(x) (((x) & BIT_MASK_SYS_SWR12_IN) << BIT_SHIFT_SYS_SWR12_IN)


#define BIT_SHIFT_SYS_SWR12_STD 12
#define BIT_MASK_SYS_SWR12_STD 0x3
#define BIT_SYS_SWR12_STD(x) (((x) & BIT_MASK_SYS_SWR12_STD) << BIT_SHIFT_SYS_SWR12_STD)


#define BIT_SHIFT_SYS_SWR12_VOL 8
#define BIT_MASK_SYS_SWR12_VOL 0xf
#define BIT_SYS_SWR12_VOL(x) (((x) & BIT_MASK_SYS_SWR12_VOL) << BIT_SHIFT_SYS_SWR12_VOL)


//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID
#define BIT_SYS_SWR_EN BIT(1)
#define BIT_SYS_SWR_LDO_EN BIT(0)

//2 REG_SYS_SWR_CTRL1
#define BIT_SYS_SW12_PFM_SEL BIT(25)
#define BIT_SYS_SW12_AUTO_ZCD_L BIT(24)
#define BIT_SYS_SW12_AUTO_MODE BIT(23)
#define BIT_SYS_SW12_LDOF_L BIT(22)
#define BIT_SYS_SW12_OCPS_L BIT(21)

#define BIT_SHIFT_SYS_SW12_TBOX 17
#define BIT_MASK_SYS_SW12_TBOX 0x3
#define BIT_SYS_SW12_TBOX(x) (((x) & BIT_MASK_SYS_SW12_TBOX) << BIT_SHIFT_SYS_SW12_TBOX)


#define BIT_SHIFT_SYS_SW12_NONOVRLAP_DLY 15
#define BIT_MASK_SYS_SW12_NONOVRLAP_DLY 0x3
#define BIT_SYS_SW12_NONOVRLAP_DLY(x) (((x) & BIT_MASK_SYS_SW12_NONOVRLAP_DLY) << BIT_SHIFT_SYS_SW12_NONOVRLAP_DLY)

#define BIT_SYS_SW12_CLAMP_DUTY BIT(14)
#define BIT_SYS_SWR12_BYPASS_SSR BIT(13)
#define BIT_SYS_SWR12_ZCDOUT_EN BIT(12)
#define BIT_SYS_SWR12_POW_ZCD BIT(11)
#define BIT_SYS_SW12_AREN BIT(10)

#define BIT_SHIFT_SYS_SWR12_OCP_CUR 7
#define BIT_MASK_SYS_SWR12_OCP_CUR 0x7
#define BIT_SYS_SWR12_OCP_CUR(x) (((x) & BIT_MASK_SYS_SWR12_OCP_CUR) << BIT_SHIFT_SYS_SWR12_OCP_CUR)

#define BIT_SYS_SWR12_OCP_EN BIT(6)

#define BIT_SHIFT_SYS_SWR12_SAWTOOTH_CF_L 4
#define BIT_MASK_SYS_SWR12_SAWTOOTH_CF_L 0x3
#define BIT_SYS_SWR12_SAWTOOTH_CF_L(x) (((x) & BIT_MASK_SYS_SWR12_SAWTOOTH_CF_L) << BIT_SHIFT_SYS_SWR12_SAWTOOTH_CF_L)


#define BIT_SHIFT_SYS_SWR12_SAWTOOTH_CFC_L 2
#define BIT_MASK_SYS_SWR12_SAWTOOTH_CFC_L 0x3
#define BIT_SYS_SWR12_SAWTOOTH_CFC_L(x) (((x) & BIT_MASK_SYS_SWR12_SAWTOOTH_CFC_L) << BIT_SHIFT_SYS_SWR12_SAWTOOTH_CFC_L)


#define BIT_SHIFT_SYS_SWR12_COMP_R3 0
#define BIT_MASK_SYS_SWR12_COMP_R3 0x3
#define BIT_SYS_SWR12_COMP_R3(x) (((x) & BIT_MASK_SYS_SWR12_COMP_R3) << BIT_SHIFT_SYS_SWR12_COMP_R3)


//2 REG_RSVD

//2 REG_RSVD

//2 REG_RSVD

//2 REG_RSVD

//2 REG_SYS_XTAL_CTRL0
#define BIT_SYS_XTAL_XQSEL BIT(31)
#define BIT_SYS_XTAL_XQSEL_RF BIT(30)

#define BIT_SHIFT_SYS_XTAL_SC_XO 24
#define BIT_MASK_SYS_XTAL_SC_XO 0x3f
#define BIT_SYS_XTAL_SC_XO(x) (((x) & BIT_MASK_SYS_XTAL_SC_XO) << BIT_SHIFT_SYS_XTAL_SC_XO)


#define BIT_SHIFT_SYS_XTAL_SC_XI 18
#define BIT_MASK_SYS_XTAL_SC_XI 0x3f
#define BIT_SYS_XTAL_SC_XI(x) (((x) & BIT_MASK_SYS_XTAL_SC_XI) << BIT_SHIFT_SYS_XTAL_SC_XI)


#define BIT_SHIFT_SYS_XTAL_GMN 13
#define BIT_MASK_SYS_XTAL_GMN 0x1f
#define BIT_SYS_XTAL_GMN(x) (((x) & BIT_MASK_SYS_XTAL_GMN) << BIT_SHIFT_SYS_XTAL_GMN)


#define BIT_SHIFT_SYS_XTAL_GMP 8
#define BIT_MASK_SYS_XTAL_GMP 0x1f
#define BIT_SYS_XTAL_GMP(x) (((x) & BIT_MASK_SYS_XTAL_GMP) << BIT_SHIFT_SYS_XTAL_GMP)

#define BIT_SYS_XTAL_EN BIT(1)
#define BIT_SYS_XTAL_BGMB_EN BIT(0)

//2 REG_SYS_XTAL_CTRL1

#define BIT_SHIFT_SYS_XTAL_COUNTER_MUX 25
#define BIT_MASK_SYS_XTAL_COUNTER_MUX 0x3
#define BIT_SYS_XTAL_COUNTER_MUX(x) (((x) & BIT_MASK_SYS_XTAL_COUNTER_MUX) << BIT_SHIFT_SYS_XTAL_COUNTER_MUX)

#define BIT_SYS_XTAL_DELAY_SYSPLL BIT(24)
#define BIT_SYS_XTAL_DELAY_USB BIT(23)
#define BIT_SYS_XTAL_DELAY_WLAFE BIT(22)
#define BIT_SYS_XTAL_AGPIO_SEL BIT(21)

#define BIT_SHIFT_SYS_XTAL_DRV_AGPIO 19
#define BIT_MASK_SYS_XTAL_DRV_AGPIO 0x3
#define BIT_SYS_XTAL_DRV_AGPIO(x) (((x) & BIT_MASK_SYS_XTAL_DRV_AGPIO) << BIT_SHIFT_SYS_XTAL_DRV_AGPIO)


#define BIT_SHIFT_SYS_XTAL_AGPIO 16
#define BIT_MASK_SYS_XTAL_AGPIO 0x7
#define BIT_SYS_XTAL_AGPIO(x) (((x) & BIT_MASK_SYS_XTAL_AGPIO) << BIT_SHIFT_SYS_XTAL_AGPIO)


#define BIT_SHIFT_SYS_XTAL_DRV_SYSPLL 14
#define BIT_MASK_SYS_XTAL_DRV_SYSPLL 0x3
#define BIT_SYS_XTAL_DRV_SYSPLL(x) (((x) & BIT_MASK_SYS_XTAL_DRV_SYSPLL) << BIT_SHIFT_SYS_XTAL_DRV_SYSPLL)

#define BIT_SYS_XTAL_GATE_SYSPLL BIT(13)

#define BIT_SHIFT_SYS_XTAL_DRV_USB 11
#define BIT_MASK_SYS_XTAL_DRV_USB 0x3
#define BIT_SYS_XTAL_DRV_USB(x) (((x) & BIT_MASK_SYS_XTAL_DRV_USB) << BIT_SHIFT_SYS_XTAL_DRV_USB)

#define BIT_SYS_XTAL_GATE_USB BIT(10)

#define BIT_SHIFT_SYS_XTAL_DRV_WLAFE 8
#define BIT_MASK_SYS_XTAL_DRV_WLAFE 0x3
#define BIT_SYS_XTAL_DRV_WLAFE(x) (((x) & BIT_MASK_SYS_XTAL_DRV_WLAFE) << BIT_SHIFT_SYS_XTAL_DRV_WLAFE)

#define BIT_SYS_XTAL_GATE_WLAFE BIT(7)

#define BIT_SHIFT_SYS_XTAL_DRV_RF2 5
#define BIT_MASK_SYS_XTAL_DRV_RF2 0x3
#define BIT_SYS_XTAL_DRV_RF2(x) (((x) & BIT_MASK_SYS_XTAL_DRV_RF2) << BIT_SHIFT_SYS_XTAL_DRV_RF2)

#define BIT_SYS_XTAL_GATE_RF2 BIT(4)

#define BIT_SHIFT_SYS_XTAL_DRV_RF1 3
#define BIT_MASK_SYS_XTAL_DRV_RF1 0x3
#define BIT_SYS_XTAL_DRV_RF1(x) (((x) & BIT_MASK_SYS_XTAL_DRV_RF1) << BIT_SHIFT_SYS_XTAL_DRV_RF1)

#define BIT_SYS_XTAL_GATE_RF1 BIT(1)

#define BIT_SHIFT_SYS_XTAL_LDO 0
#define BIT_MASK_SYS_XTAL_LDO 0x3
#define BIT_SYS_XTAL_LDO(x) (((x) & BIT_MASK_SYS_XTAL_LDO) << BIT_SHIFT_SYS_XTAL_LDO)


//2 REG_RSVD

//2 REG_RSVD

//2 REG_SYS_SYSPLL_CTRL0

#define BIT_SHIFT_SYS_SYSPLL_LPF_R3 29
#define BIT_MASK_SYS_SYSPLL_LPF_R3 0x7
#define BIT_SYS_SYSPLL_LPF_R3(x) (((x) & BIT_MASK_SYS_SYSPLL_LPF_R3) << BIT_SHIFT_SYS_SYSPLL_LPF_R3)


#define BIT_SHIFT_SYS_SYSPLL_LPF_CS 27
#define BIT_MASK_SYS_SYSPLL_LPF_CS 0x3
#define BIT_SYS_SYSPLL_LPF_CS(x) (((x) & BIT_MASK_SYS_SYSPLL_LPF_CS) << BIT_SHIFT_SYS_SYSPLL_LPF_CS)


#define BIT_SHIFT_SYS_SYSPLL_LPF_CP 25
#define BIT_MASK_SYS_SYSPLL_LPF_CP 0x3
#define BIT_SYS_SYSPLL_LPF_CP(x) (((x) & BIT_MASK_SYS_SYSPLL_LPF_CP) << BIT_SHIFT_SYS_SYSPLL_LPF_CP)


#define BIT_SHIFT_SYS_SYSPLL_LPF_C3 23
#define BIT_MASK_SYS_SYSPLL_LPF_C3 0x3
#define BIT_SYS_SYSPLL_LPF_C3(x) (((x) & BIT_MASK_SYS_SYSPLL_LPF_C3) << BIT_SHIFT_SYS_SYSPLL_LPF_C3)

#define BIT_SYS_SYSPLL_WDOG_ENB BIT(22)
#define BIT_SYS_SYSPLL_CKTST_EN BIT(21)

#define BIT_SHIFT_SYS_SYSPLL_MONCK_SEL 18
#define BIT_MASK_SYS_SYSPLL_MONCK_SEL 0x7
#define BIT_SYS_SYSPLL_MONCK_SEL(x) (((x) & BIT_MASK_SYS_SYSPLL_MONCK_SEL) << BIT_SHIFT_SYS_SYSPLL_MONCK_SEL)


#define BIT_SHIFT_SYS_SYSPLL_CP_IOFFSET 13
#define BIT_MASK_SYS_SYSPLL_CP_IOFFSET 0x1f
#define BIT_SYS_SYSPLL_CP_IOFFSET(x) (((x) & BIT_MASK_SYS_SYSPLL_CP_IOFFSET) << BIT_SHIFT_SYS_SYSPLL_CP_IOFFSET)

#define BIT_SYS_SYSPLL_CP_IDOUBLE BIT(12)

#define BIT_SHIFT_SYS_SYSPLL_CP_BIAS 9
#define BIT_MASK_SYS_SYSPLL_CP_BIAS 0x7
#define BIT_SYS_SYSPLL_CP_BIAS(x) (((x) & BIT_MASK_SYS_SYSPLL_CP_BIAS) << BIT_SHIFT_SYS_SYSPLL_CP_BIAS)

#define BIT_SYS_SYSPLL_FREF_EDGE BIT(8)
#define BIT_SYS_SYSPLL_EN BIT(1)
#define BIT_SYS_SYSPLL_LVPC_EN BIT(0)

//2 REG_SYS_SYSPLL_CTRL1
#define BIT_SYS_SYSPLL_DIV5_3 BIT(17)
#define BIT_SYS_SYSPLL_CK500K_SEL BIT(15)
#define BIT_SYS_SYSPLL_CK200M_EN BIT(14)
#define BIT_SYS_SYSPLL_CKSDR_EN BIT(13)

#define BIT_SHIFT_SYS_SYSPLL_CKSDR_DIV 11
#define BIT_MASK_SYS_SYSPLL_CKSDR_DIV 0x3
#define BIT_SYS_SYSPLL_CKSDR_DIV(x) (((x) & BIT_MASK_SYS_SYSPLL_CKSDR_DIV) << BIT_SHIFT_SYS_SYSPLL_CKSDR_DIV)

#define BIT_SYS_SYSPLL_CK24P576_EN BIT(9)
#define BIT_SYS_SYSPLL_CK22P5792_EN BIT(8)
#define BIT_SYS_SYSPLL_CK_PS_EN BIT(6)

#define BIT_SHIFT_SYS_SYSPLL_CK_PS_SEL 3
#define BIT_MASK_SYS_SYSPLL_CK_PS_SEL 0x7
#define BIT_SYS_SYSPLL_CK_PS_SEL(x) (((x) & BIT_MASK_SYS_SYSPLL_CK_PS_SEL) << BIT_SHIFT_SYS_SYSPLL_CK_PS_SEL)


#define BIT_SHIFT_SYS_SYSPLL_LPF_RS 0
#define BIT_MASK_SYS_SYSPLL_LPF_RS 0x7
#define BIT_SYS_SYSPLL_LPF_RS(x) (((x) & BIT_MASK_SYS_SYSPLL_LPF_RS) << BIT_SHIFT_SYS_SYSPLL_LPF_RS)


//2 REG_SYS_SYSPLL_CTRL2

#define BIT_SHIFT_XTAL_DRV_RF_LATCH 0
#define BIT_MASK_XTAL_DRV_RF_LATCH 0xffffffffL
#define BIT_XTAL_DRV_RF_LATCH(x) (((x) & BIT_MASK_XTAL_DRV_RF_LATCH) << BIT_SHIFT_XTAL_DRV_RF_LATCH)


//2 REG_RSVD

//2 REG_RSVD

#define BIT_SHIFT_PESOC_CPU_OCP_CK_SEL 0
#define BIT_MASK_PESOC_CPU_OCP_CK_SEL 0x7
#define BIT_PESOC_CPU_OCP_CK_SEL(x) (((x) & BIT_MASK_PESOC_CPU_OCP_CK_SEL) << BIT_SHIFT_PESOC_CPU_OCP_CK_SEL)


//2 REG_RSVD

//2 REG_RSVD

//2 REG_

//2 REG_SYS_ANA_TIM_CTRL

#define BIT_SHIFT_SYS_ANACK_TU_TIME 16
#define BIT_MASK_SYS_ANACK_TU_TIME 0x3f
#define BIT_SYS_ANACK_TU_TIME(x) (((x) & BIT_MASK_SYS_ANACK_TU_TIME) << BIT_SHIFT_SYS_ANACK_TU_TIME)

#define BIT_SYS_DSBYCNT_EN BIT(15)

#define BIT_SHIFT_SYS_DSTDY_TIM_SCAL 8
#define BIT_MASK_SYS_DSTDY_TIM_SCAL 0xf
#define BIT_SYS_DSTDY_TIM_SCAL(x) (((x) & BIT_MASK_SYS_DSTDY_TIM_SCAL) << BIT_SHIFT_SYS_DSTDY_TIM_SCAL)


#define BIT_SHIFT_SYS_DSTBY_TIM_PERIOD 0
#define BIT_MASK_SYS_DSTBY_TIM_PERIOD 0xff
#define BIT_SYS_DSTBY_TIM_PERIOD(x) (((x) & BIT_MASK_SYS_DSTBY_TIM_PERIOD) << BIT_SHIFT_SYS_DSTBY_TIM_PERIOD)


//2 REG_SYS_DSLP_TIM_CTRL

#define BIT_SHIFT_SYS_REGU_ASIF_EN 24
#define BIT_MASK_SYS_REGU_ASIF_EN 0xff
#define BIT_SYS_REGU_ASIF_EN(x) (((x) & BIT_MASK_SYS_REGU_ASIF_EN) << BIT_SHIFT_SYS_REGU_ASIF_EN)


#define BIT_SHIFT_SYS_REGU_ASIF_THP_DA 20
#define BIT_MASK_SYS_REGU_ASIF_THP_DA 0x3
#define BIT_SYS_REGU_ASIF_THP_DA(x) (((x) & BIT_MASK_SYS_REGU_ASIF_THP_DA) << BIT_SHIFT_SYS_REGU_ASIF_THP_DA)


#define BIT_SHIFT_SYS_REGU_ASIF_TPD_CK 18
#define BIT_MASK_SYS_REGU_ASIF_TPD_CK 0x3
#define BIT_SYS_REGU_ASIF_TPD_CK(x) (((x) & BIT_MASK_SYS_REGU_ASIF_TPD_CK) << BIT_SHIFT_SYS_REGU_ASIF_TPD_CK)


#define BIT_SHIFT_SYS_REGU_ASIF_TSP_DA 16
#define BIT_MASK_SYS_REGU_ASIF_TSP_DA 0x3
#define BIT_SYS_REGU_ASIF_TSP_DA(x) (((x) & BIT_MASK_SYS_REGU_ASIF_TSP_DA) << BIT_SHIFT_SYS_REGU_ASIF_TSP_DA)

#define BIT_SYS_REGU_ASIF_POLL BIT(15)
#define BIT_SYS_REGU_ASIF_MODE BIT(14)
#define BIT_SYS_REGU_ASIF_WE BIT(12)

#define BIT_SHIFT_SYS_REGU_ASIF_AD 8
#define BIT_MASK_SYS_REGU_ASIF_AD 0xf
#define BIT_SYS_REGU_ASIF_AD(x) (((x) & BIT_MASK_SYS_REGU_ASIF_AD) << BIT_SHIFT_SYS_REGU_ASIF_AD)


#define BIT_SHIFT_SYS_REGU_ASIF_WD 0
#define BIT_MASK_SYS_REGU_ASIF_WD 0xff
#define BIT_SYS_REGU_ASIF_WD(x) (((x) & BIT_MASK_SYS_REGU_ASIF_WD) << BIT_SHIFT_SYS_REGU_ASIF_WD)


//2 REG_SYS_DSLP_TIM_CAL_CTRL
#define BIT_SYS_DSLP_TIM_EN BIT(24)

#define BIT_SHIFT_SYS_DSLP_TIM_PERIOD 0
#define BIT_MASK_SYS_DSLP_TIM_PERIOD 0x7fffff
#define BIT_SYS_DSLP_TIM_PERIOD(x) (((x) & BIT_MASK_SYS_DSLP_TIM_PERIOD) << BIT_SHIFT_SYS_DSLP_TIM_PERIOD)


//2 REG_RSVD

//2 REG_SYS_DEBUG_CTRL
#define BIT_SYS_DBG_PIN_EN BIT(0)

//2 REG_SYS_PINMUX_CTRL
#define BIT_EEPROM_PIN_EN BIT(4)
#define BIT_SIC_PIN_EN BIT(0)

//2 REG_SYS_GPIO_DSTBY_WAKE_CTRL0
#define BIT_SYS_GPIOE3_WEVENT_STS BIT(27)
#define BIT_SYS_GPIOD5_WEVENT_STS BIT(26)
#define BIT_SYS_GPIOC7_WEVENT_STS BIT(25)
#define BIT_SYS_GPIOA5_WEVENT_STS BIT(24)
#define BIT_SYS_GPIO_GPE3_PULL_CTRL_EN BIT(19)
#define BIT_SYS_GPIO_GPD5_PULL_CTRL_EN BIT(18)
#define BIT_SYS_GPIO_GPC7_PULL_CTRL_EN BIT(17)
#define BIT_SYS_GPIO_GPA5_PULL_CTRL_EN BIT(16)
#define BIT_SYS_GPIOE3_WINT_MODE BIT(11)
#define BIT_SYS_GPIOD5_WINT_MODE BIT(10)
#define BIT_SYS_GPIOC7_WINT_MODE BIT(9)
#define BIT_SYS_GPIOA5_WINT_MODE BIT(8)
#define BIT_SYS_GPIOE3_PIN_EN BIT(3)
#define BIT_SYS_GPIOD5_PIN_EN BIT(2)
#define BIT_SYS_GPIOC7_PIN_EN BIT(1)
#define BIT_SYS_GPIOA5_PIN_EN BIT(0)

//2 REG_SYS_GPIO_DSTBY_WAKE_CTRL1
#define BIT_SYS_GPIOE3_SHTDN_N BIT(19)
#define BIT_SYS_GPIOD5_SHTDN_N BIT(18)
#define BIT_SYS_GPIOC7_SHTDN_N BIT(17)
#define BIT_SYS_GPIOA5_SHTDN_N BIT(16)

#define BIT_SHIFT_SYS_WINT_DEBOUNCE_TIM_SCAL 8
#define BIT_MASK_SYS_WINT_DEBOUNCE_TIM_SCAL 0x3
#define BIT_SYS_WINT_DEBOUNCE_TIM_SCAL(x) (((x) & BIT_MASK_SYS_WINT_DEBOUNCE_TIM_SCAL) << BIT_SHIFT_SYS_WINT_DEBOUNCE_TIM_SCAL)

#define BIT_SYS_GPIOE3_WINT_DEBOUNCE_EN BIT(3)
#define BIT_SYS_GPIOD5_WINT_DEBOUNCE_EN BIT(2)
#define BIT_SYS_GPIOC7_WINT_DEBOUNCE_EN BIT(1)
#define BIT_SYS_GPIOA5_WINT_DEBOUNCE_EN BIT(0)

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_SYS_DEBUG_REG

#define BIT_SHIFT_SYS_DBG_VALUE 0
#define BIT_MASK_SYS_DBG_VALUE 0xffffffffL
#define BIT_SYS_DBG_VALUE(x) (((x) & BIT_MASK_SYS_DBG_VALUE) << BIT_SHIFT_SYS_DBG_VALUE)


//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_SYS_EEPROM_CTRL0

#define BIT_SHIFT_EFUSE_UNLOCK 24
#define BIT_MASK_EFUSE_UNLOCK 0xff
#define BIT_EFUSE_UNLOCK(x) (((x) & BIT_MASK_EFUSE_UNLOCK) << BIT_SHIFT_EFUSE_UNLOCK)


//2 REG_NOT_VALID
#define BIT_SYS_EFUSE_LDALL BIT(16)

#define BIT_SHIFT_SYS_EEPROM_VPDIDX 8
#define BIT_MASK_SYS_EEPROM_VPDIDX 0xff
#define BIT_SYS_EEPROM_VPDIDX(x) (((x) & BIT_MASK_SYS_EEPROM_VPDIDX) << BIT_SHIFT_SYS_EEPROM_VPDIDX)


#define BIT_SHIFT_SYS_EEPROM_MD 6
#define BIT_MASK_SYS_EEPROM_MD 0x3
#define BIT_SYS_EEPROM_MD(x) (((x) & BIT_MASK_SYS_EEPROM_MD) << BIT_SHIFT_SYS_EEPROM_MD)

#define BIT_SYS_AUTOLOAD_SUS BIT(5)
#define BIT_SYS_EEPROM_SEL BIT(4)
#define BIT_SYS_EEPROM_EECS BIT(3)
#define BIT_SYS_EEPROM_EESK BIT(2)
#define BIT_SYS_EEPROM_EEDI BIT(1)
#define BIT_SYS_EEPROM_EEDO BIT(0)

//2 REG_SYS_EEPROM_CTRL1

#define BIT_SHIFT_SYS_EEPROM_VPD 0
#define BIT_MASK_SYS_EEPROM_VPD 0xffffffffL
#define BIT_SYS_EEPROM_VPD(x) (((x) & BIT_MASK_SYS_EEPROM_VPD) << BIT_SHIFT_SYS_EEPROM_VPD)


//2 REG_SYS_EFUSE_CTRL
#define BIT_SYS_EF_RWFLAG BIT(31)

#define BIT_SHIFT_SYS_EF_PGPD 28
#define BIT_MASK_SYS_EF_PGPD 0x7
#define BIT_SYS_EF_PGPD(x) (((x) & BIT_MASK_SYS_EF_PGPD) << BIT_SHIFT_SYS_EF_PGPD)


#define BIT_SHIFT_SYS_EF_RDT 24
#define BIT_MASK_SYS_EF_RDT 0xf
#define BIT_SYS_EF_RDT(x) (((x) & BIT_MASK_SYS_EF_RDT) << BIT_SHIFT_SYS_EF_RDT)


#define BIT_SHIFT_SYS_EF_PGTS 20
#define BIT_MASK_SYS_EF_PGTS 0xf
#define BIT_SYS_EF_PGTS(x) (((x) & BIT_MASK_SYS_EF_PGTS) << BIT_SHIFT_SYS_EF_PGTS)

#define BIT_SYS_EF_PDWN BIT(19)
#define BIT_SYS_EF_ALDEN BIT(18)

#define BIT_SHIFT_SYS_EF_ADDR 8
#define BIT_MASK_SYS_EF_ADDR 0x3ff
#define BIT_SYS_EF_ADDR(x) (((x) & BIT_MASK_SYS_EF_ADDR) << BIT_SHIFT_SYS_EF_ADDR)


#define BIT_SHIFT_SYS_EF_DATA 0
#define BIT_MASK_SYS_EF_DATA 0xff
#define BIT_SYS_EF_DATA(x) (((x) & BIT_MASK_SYS_EF_DATA) << BIT_SHIFT_SYS_EF_DATA)


//2 REG_SYS_EFUSE_TEST
#define BIT_SYS_EF_CRES_SEL BIT(26)

#define BIT_SHIFT_SYS_EF_SCAN_START 16
#define BIT_MASK_SYS_EF_SCAN_START 0x1ff
#define BIT_SYS_EF_SCAN_START(x) (((x) & BIT_MASK_SYS_EF_SCAN_START) << BIT_SHIFT_SYS_EF_SCAN_START)


#define BIT_SHIFT_SYS_EF_SCAN_END 12
#define BIT_MASK_SYS_EF_SCAN_END 0xf
#define BIT_SYS_EF_SCAN_END(x) (((x) & BIT_MASK_SYS_EF_SCAN_END) << BIT_SHIFT_SYS_EF_SCAN_END)

#define BIT_SYS_EF_FORCE_PGMEN BIT(11)

#define BIT_SHIFT_SYS_EF_CELL_SEL 8
#define BIT_MASK_SYS_EF_CELL_SEL 0x3
#define BIT_SYS_EF_CELL_SEL(x) (((x) & BIT_MASK_SYS_EF_CELL_SEL) << BIT_SHIFT_SYS_EF_CELL_SEL)

#define BIT_SYS_EF_TRPT BIT(7)

#define BIT_SHIFT_SYS_EF_SCAN_TTHD 0
#define BIT_MASK_SYS_EF_SCAN_TTHD 0x7f
#define BIT_SYS_EF_SCAN_TTHD(x) (((x) & BIT_MASK_SYS_EF_SCAN_TTHD) << BIT_SHIFT_SYS_EF_SCAN_TTHD)


//2 REG_SYS_DSTBY_INFO0

//2 REG_NOT_VALID

//2 REG_SYS_DSTBY_INFO1

//2 REG_SYS_DSTBY_INFO2

//2 REG_NOT_VALID

//2 REG_SYS_DSTBY_INFO3

//2 REG_SYS_SLP_WAKE_EVENT_MSK0
#define BIT_SYSON_WEVT_GPIO_DSTBY_MSK BIT(29)
#define BIT_SYSON_WEVT_A33_MSK BIT(28)
#define BIT_SYSON_WEVT_ADC_MSK BIT(26)
#define BIT_SYSON_WEVT_I2C_MSK BIT(24)
#define BIT_SYSON_WEVT_SPI_MSK BIT(22)
#define BIT_SYSON_WEVT_UART_MSK BIT(20)
#define BIT_SYSON_WEVT_USB_MSK BIT(16)
#define BIT_SYSON_WEVT_SDIO_MSK BIT(14)
#define BIT_SYSON_WEVT_NFC_MSK BIT(9)
#define BIT_SYSON_WEVT_WLAN_MSK BIT(8)
#define BIT_SYSON_WEVT_GPIO_MSK BIT(4)
#define BIT_SYSON_WEVT_CHIP_EN_MSK BIT(3)
#define BIT_SYSON_WEVT_OVER_CURRENT_MSK BIT(2)
#define BIT_SYSON_WEVT_GTIM_MSK BIT(1)
#define BIT_SYSON_WEVT_SYSTIM_MSK BIT(0)

//2 REG_SYS_SLP_WAKE_EVENT_MSK1

//2 REG_SYS_SLP_WAKE_EVENT_STATUS0
#define BIT_SYSON_WEVT_GPIO_DSTBY_STS BIT(29)
#define BIT_SYSON_WEVT_A33_STS BIT(28)
#define BIT_SYSON_WEVT_ADC_STS BIT(26)
#define BIT_SYSON_WEVT_I2C_STS BIT(24)
#define BIT_SYSON_WEVT_SPI_STS BIT(22)
#define BIT_SYSON_WEVT_UART_STS BIT(20)
#define BIT_SYSON_WEVT_USB_STS BIT(16)
#define BIT_SYSON_WEVT_SDIO_STS BIT(14)
#define BIT_SYSON_WEVT_NFC_STS BIT(9)
#define BIT_SYSON_WEVT_WLAN_STS BIT(8)
#define BIT_SYSON_WEVT_GPIO_STS BIT(4)
#define BIT_SYSON_WEVT_CHIP_EN_STS BIT(3)
#define BIT_SYSON_WEVT_OVER_CURRENT_STS BIT(2)
#define BIT_SYSON_WEVT_GTIM_STS BIT(1)
#define BIT_SYSON_WEVT_SYSTIM_STS BIT(0)

//2 REG_SYS_SLP_WAKE_EVENT_STATUS1

//2 REG_SYS_SNF_WAKE_EVENT_MSK0

#define BIT_SHIFT_SYS_WKPERI_IMR0 1
#define BIT_MASK_SYS_WKPERI_IMR0 0x7fffffffL
#define BIT_SYS_WKPERI_IMR0(x) (((x) & BIT_MASK_SYS_WKPERI_IMR0) << BIT_SHIFT_SYS_WKPERI_IMR0)

#define BIT_SYSON_SNFEVT_ADC_MSK BIT(0)

//2 REG_SYS_SNF_WAKE_EVENT_STATUS

#define BIT_SHIFT_SYS_WKPERI_ISR0 1
#define BIT_MASK_SYS_WKPERI_ISR0 0x7fffffffL
#define BIT_SYS_WKPERI_ISR0(x) (((x) & BIT_MASK_SYS_WKPERI_ISR0) << BIT_SHIFT_SYS_WKPERI_ISR0)

#define BIT_SYSON_SNFEVT_ADC_STS BIT(0)

//2 REG_SYS_PWRMGT_CTRL
#define BIT_SYSON_REGU_DSLP BIT(7)

//2 REG_NOT_VALID
#define BIT_SYSON_PM_CMD_SLP BIT(2)
#define BIT_SYSON_PM_CMD_DSTBY BIT(1)
#define BIT_SYSON_PM_CMD_DSLP BIT(0)

//2 REG_RSVD

//2 REG_SYS_PWRMGT_OPTION
#define BIT_SYSON_PMOPT_NORM_SYSCLK_SEL BIT(30)
#define BIT_SYSON_PMOPT_NORM_SYSPLL_EN BIT(29)
#define BIT_SYSON_PMOPT_NORM_XTAL_EN BIT(28)
#define BIT_SYSON_PMOPT_NORM_EN_SOC BIT(27)
#define BIT_SYSON_PMOPT_NORM_EN_PWM BIT(26)
#define BIT_SYSON_PMOPT_NORM_EN_SWR BIT(25)
#define BIT_SYSON_PMOPT_NORM_LPLDO_SEL BIT(24)
#define BIT_SYSON_PMOPT_SNZ_SYSCLK_SEL BIT(22)
#define BIT_SYSON_PMOPT_SNZ_SYSPLL_EN BIT(21)
#define BIT_SYSON_PMOPT_SNZ_XTAL_EN BIT(20)
#define BIT_SYSON_PMOPT_SNZ_EN_SOC BIT(19)
#define BIT_SYSON_PMOPT_SNZ_EN_PWM BIT(18)
#define BIT_SYSON_PMOPT_SNZ_EN_SWR BIT(17)
#define BIT_SYSON_PMOPT_SNZ_LPLDO_SEL BIT(16)
#define BIT_SYSON_PMOPT_SLP_SYSCLK_SEL BIT(14)
#define BIT_SYSON_PMOPT_SLP_SYSPLL_EN BIT(13)
#define BIT_SYSON_PMOPT_SLP_XTAL_EN BIT(12)
#define BIT_SYSON_PMOPT_SLP_EN_SOC BIT(11)
#define BIT_SYSON_PMOPT_SLP_EN_PWM BIT(10)
#define BIT_SYSON_PMOPT_SLP_EN_SWR BIT(9)
#define BIT_SYSON_PMOPT_SLP_LPLDO_SEL BIT(8)
#define BIT_SYSON_PMOPT_DSTBY_SYSCLK_SEL BIT(6)
#define BIT_SYSON_PMOPT_DSTBY_SYSPLL_EN BIT(5)
#define BIT_SYSON_PMOPT_DSTBY_XTAL_EN BIT(4)
#define BIT_SYSON_PMOPT_DSTBY_EN_SOC BIT(3)
#define BIT_SYSON_PMOPT_DSTBY_EN_PWM BIT(2)
#define BIT_SYSON_PMOPT_DSTBY_EN_SWR BIT(1)
#define BIT_SYSON_PMOPT_DSTBY_LPLDO_SEL BIT(0)

//2 REG_SYS_PWRMGT_OPTION_EXT
#define BIT_SYSON_PMOPT_SLP_ANACK_SEL BIT(2)
#define BIT_SYSON_PMOPT_SLP_ANACK_EN BIT(1)
#define BIT_SYSON_PMOPT_SLP_SWR_ADJ BIT(0)

//2 REG_SYS_DSLP_WEVENT
#define BIT_SYSON_DSLP_GPIO BIT(2)
#define BIT_SYSON_DSLP_NFC BIT(1)
#define BIT_SYSON_DSLP_WTIMER33 BIT(0)

//2 REG_SYS_PERI_MONITOR
#define BIT_SYSON_ISO33_NFC BIT(0)

//2 REG_SYS_SYSTEM_CFG0
#define BIT_SYSCFG_BD_PKG_SEL BIT(31)

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_NOT_VALID

#define BIT_SHIFT_VENDOR_ID 8
#define BIT_MASK_VENDOR_ID 0xf
#define BIT_VENDOR_ID(x) (((x) & BIT_MASK_VENDOR_ID) << BIT_SHIFT_VENDOR_ID)


#define BIT_SHIFT_CHIP_VER 4
#define BIT_MASK_CHIP_VER 0xf
#define BIT_CHIP_VER(x) (((x) & BIT_MASK_CHIP_VER) << BIT_SHIFT_CHIP_VER)


#define BIT_SHIFT_RF_RL_ID 0
#define BIT_MASK_RF_RL_ID 0xf
#define BIT_RF_RL_ID(x) (((x) & BIT_MASK_RF_RL_ID) << BIT_SHIFT_RF_RL_ID)


//2 REG_SYS_SYSTEM_CFG1

#define BIT_SHIFT_SYSCFG_TRP_ICFG 28
#define BIT_MASK_SYSCFG_TRP_ICFG 0xf
#define BIT_SYSCFG_TRP_ICFG(x) (((x) & BIT_MASK_SYSCFG_TRP_ICFG) << BIT_SHIFT_SYSCFG_TRP_ICFG)

#define BIT_SYSCFG_TRP_BOOT_SEL_ BIT(27)
#define BIT_SysCFG_TRP_SPSLDO_SEL BIT(26)
#define BIT_V15_VLD BIT(16)
#define BIT_SYS_SYSPLL_CLK_RDY BIT(9)
#define BIT_SYS_XCLK_VLD BIT(8)
#define BIT_SYSCFG_ALDN_STS BIT(0)

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_NOT_VALID

//2 REG_RSVD

//2 REG_NOT_VALID

//2 REG_NOT_VALID


//================= Register Address Definition =====================//
#define REG_SYS_PWR_CTRL 0x0000
#define REG_SYS_ISO_CTRL 0x0002
#define REG_SYS_FUNC_EN 0x0008
#define REG_SYS_CLK_CTRL0 0x0010
#define REG_SYS_CLK_CTRL1 0x0014
#define REG_SYS_EFUSE_SYSCFG0 0x0020
#define REG_SYS_EFUSE_SYSCFG1 0x0024
#define REG_SYS_EFUSE_SYSCFG2 0x0028
#define REG_SYS_EFUSE_SYSCFG3 0x002C
#define REG_SYS_EFUSE_SYSCFG4 0x0030
#define REG_SYS_EFUSE_SYSCFG5 0x0034
#define REG_SYS_EFUSE_SYSCFG6 0x0038
#define REG_SYS_EFUSE_SYSCFG7 0x003C
#define REG_SYS_REGU_CTRL0 0x0040
#define REG_SYS_SWR_CTRL0 0x0048
#define REG_SYS_SWR_CTRL1 0x004C
#define REG_SYS_XTAL_CTRL0 0x0060
#define REG_SYS_XTAL_CTRL1 0x0064
#define REG_SYS_SYSPLL_CTRL0 0x0070
#define REG_SYS_SYSPLL_CTRL1 0x0074
#define REG_SYS_SYSPLL_CTRL2 0x0078
#define REG_SYS_ANA_TIM_CTRL 0x0090
#define REG_SYS_DSLP_TIM_CTRL 0x0094
#define REG_SYS_DSLP_TIM_CAL_CTRL 0x0098
#define REG_SYS_DEBUG_CTRL 0x00A0
#define REG_SYS_PINMUX_CTRL 0x00A4
#define REG_SYS_GPIO_DSTBY_WAKE_CTRL0 0x00A8
#define REG_SYS_GPIO_DSTBY_WAKE_CTRL1 0x00AC
#define REG_SYS_DEBUG_REG 0x00BC
#define REG_SYS_EEPROM_CTRL0 0x00E0
#define REG_SYS_EEPROM_CTRL1 0x00E4
#define REG_SYS_EFUSE_CTRL 0x00E8
#define REG_SYS_EFUSE_TEST 0x00EC
#define REG_SYS_DSTBY_INFO0 0x00F0
#define REG_SYS_DSTBY_INFO1 0x00F4
#define REG_SYS_DSTBY_INFO2 0x00F8
#define REG_SYS_DSTBY_INFO3 0x00FC
#define REG_SYS_SLP_WAKE_EVENT_MSK0 0x0100
#define REG_SYS_SLP_WAKE_EVENT_MSK1 0x0104
#define REG_SYS_SLP_WAKE_EVENT_STATUS0 0x0108
#define REG_SYS_SLP_WAKE_EVENT_STATUS1 0x010C
#define REG_SYS_SNF_WAKE_EVENT_MSK0 0x0110
#define REG_SYS_SNF_WAKE_EVENT_STATUS 0x0114
#define REG_SYS_PWRMGT_CTRL 0x0118
#define REG_SYS_PWRMGT_OPTION 0x0120
#define REG_SYS_PWRMGT_OPTION_EXT 0x0124
#define REG_SYS_DSLP_WEVENT 0x0130
#define REG_SYS_PERI_MONITOR 0x0134
#define REG_SYS_SYSTEM_CFG0 0x01F0
#define REG_SYS_SYSTEM_CFG1 0x01F4
#define REG_SYS_SYSTEM_CFG2 0x01F8


#endif
