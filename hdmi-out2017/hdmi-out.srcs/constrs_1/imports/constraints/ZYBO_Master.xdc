## This file is a general .xdc for the ZYBO Rev B board
## To use it in a project:
## - uncomment the lines corresponding to used pins
## - rename the used signals according to the project

##Clock signal
##IO_L11P_T1_SRCC_35	
#set_property PACKAGE_PIN L16 [get_ports clk]
#set_property IOSTANDARD LVCMOS33 [get_ports clk]
#create_clock -add -name sys_clk_pin -period 8.00 -waveform {0 4} [get_ports clk]

##Switches
##IO_L19N_T3_VREF_35
#set_property PACKAGE_PIN G15 [get_ports {sw[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {sw[0]}]

##IO_L24P_T3_34
#set_property PACKAGE_PIN P15 [get_ports {sw[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {sw[1]}]

##IO_L4N_T0_34
#set_property PACKAGE_PIN W13 [get_ports {sw[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {sw[2]}]

##IO_L9P_T1_DQS_34
#set_property PACKAGE_PIN T16 [get_ports {sw[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {sw[3]}]

##Buttons
##IO_L20N_T3_34
set_property PACKAGE_PIN R18 [get_ports {btn[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {btn[0]}]

##IO_L24N_T3_34
set_property PACKAGE_PIN P16 [get_ports {btn[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {btn[1]}]

##IO_L18P_T2_34
set_property PACKAGE_PIN V16 [get_ports {btn[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {btn[2]}]

##IO_L7P_T1_34
set_property PACKAGE_PIN Y16 [get_ports {btn[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {btn[3]}]

##LEDs
##IO_L23P_T3_35
#set_property PACKAGE_PIN M14 [get_ports {led[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {led[0]}]

##IO_L23N_T3_35
#set_property PACKAGE_PIN M15 [get_ports {led[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {led[1]}]

##IO_0_35
#set_property PACKAGE_PIN G14 [get_ports {led[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {led[2]}]

##IO_L3N_T0_DQS_AD1N_35
#set_property PACKAGE_PIN D18 [get_ports {led[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {led[3]}]

##I2S Audio Codec
##IO_L12N_T1_MRCC_35
#set_property PACKAGE_PIN K18 [get_ports ac_bclk]
#set_property IOSTANDARD LVCMOS33 [get_ports ac_bclk]

##IO_25_34
#set_property PACKAGE_PIN T19 [get_ports ac_mclk]
#set_property IOSTANDARD LVCMOS33 [get_ports ac_mclk]

##IO_L23N_T3_34
#set_property PACKAGE_PIN P18 [get_ports ac_muten]
#set_property IOSTANDARD LVCMOS33 [get_ports ac_muten]

##IO_L8P_T1_AD10P_35
#set_property PACKAGE_PIN M17 [get_ports ac_pbdat]
#set_property IOSTANDARD LVCMOS33 [get_ports ac_pbdat]

##IO_L11N_T1_SRCC_35
#set_property PACKAGE_PIN L17 [get_ports ac_pblrc]
#set_property IOSTANDARD LVCMOS33 [get_ports ac_pblrc]

##IO_L12P_T1_MRCC_35
#set_property PACKAGE_PIN K17 [get_ports ac_recdat]
#set_property IOSTANDARD LVCMOS33 [get_ports ac_recdat]

##IO_L8N_T1_AD10N_35
#set_property PACKAGE_PIN M18 [get_ports ac_reclrc]
#set_property IOSTANDARD LVCMOS33 [get_ports ac_reclrc]

##Audio Codec/external EEPROM IIC bus
#IO_L13P_T2_MRCC_34
set_property PACKAGE_PIN N18 [get_ports iic_0_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports iic_0_scl_io]

#IO_L23P_T3_34
set_property PACKAGE_PIN N17 [get_ports iic_0_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports iic_0_sda_io]

##Additional Ethernet signals
##IO_L6P_T0_35
#set_property PACKAGE_PIN F16 [get_ports eth_int_b]
#set_property IOSTANDARD LVCMOS33 [get_ports eth_int_b]

##IO_L3P_T0_DQS_AD1P_35
#set_property PACKAGE_PIN E17 [get_ports eth_rst_b]
#set_property IOSTANDARD LVCMOS33 [get_ports eth_rst_b]

##HDMI Signals
#IO_L13N_T2_MRCC_35
set_property IOSTANDARD TMDS_33 [get_ports TMDS_clk_n]

#IO_L13P_T2_MRCC_35
set_property PACKAGE_PIN H16 [get_ports TMDS_clk_p]
set_property IOSTANDARD TMDS_33 [get_ports TMDS_clk_p]

#IO_L4N_T0_35
set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_n[0]}]

#IO_L4P_T0_35
set_property PACKAGE_PIN D19 [get_ports {TMDS_data_p[0]}]
set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_p[0]}]

#IO_L1N_T0_AD0N_35
set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_n[1]}]

#IO_L1P_T0_AD0P_35
set_property PACKAGE_PIN C20 [get_ports {TMDS_data_p[1]}]
set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_p[1]}]

#IO_L2N_T0_AD8N_35
set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_n[2]}]

#IO_L2P_T0_AD8P_35
set_property PACKAGE_PIN B19 [get_ports {TMDS_data_p[2]}]
set_property IOSTANDARD TMDS_33 [get_ports {TMDS_data_p[2]}]

##IO_L5N_T0_AD9N_35
#set_property PACKAGE_PIN E19 [get_ports hdmi_cec]
#set_property IOSTANDARD LVCMOS33 [get_ports hdmi_cec]

#IO_L5P_T0_AD9P_35
set_property PACKAGE_PIN E18 [get_ports {hdmi_hpd_tri_i[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {hdmi_hpd_tri_i[0]}]

##IO_L6N_T0_VREF_35
set_property PACKAGE_PIN F17 [get_ports {HDMI_OEN[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {HDMI_OEN[0]}]

#IO_L16P_T2_35
set_property PACKAGE_PIN G17 [get_ports hdmi_ddc_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports hdmi_ddc_scl_io]

#IO_L16N_T2_35
set_property PACKAGE_PIN G18 [get_ports hdmi_ddc_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports hdmi_ddc_sda_io]

##Pmod Header JA (XADC)
##IO_L21N_T3_DQS_AD14N_35
#set_property PACKAGE_PIN N16 [get_ports {ja_n[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {ja_n[0]}]

##IO_L21P_T3_DQS_AD14P_35
#set_property PACKAGE_PIN N15 [get_ports {ja_p[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {ja_p[0]}]

##IO_L22N_T3_AD7N_35
#set_property PACKAGE_PIN L15 [get_ports {ja_n[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {ja_n[1]}]

##IO_L22P_T3_AD7P_35
#set_property PACKAGE_PIN L14 [get_ports {ja_p[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {ja_p[1]}]

##IO_L24N_T3_AD15N_35
#set_property PACKAGE_PIN J16 [get_ports {ja_n[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {ja_n[2]}]

##IO_L24P_T3_AD15P_35
#set_property PACKAGE_PIN K16 [get_ports {ja_p[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {ja_p[2]}]

##IO_L20N_T3_AD6N_35
#set_property PACKAGE_PIN J14 [get_ports {ja_n[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {ja_n[3]}]

##IO_L20P_T3_AD6P_35
#set_property PACKAGE_PIN K14 [get_ports {ja_p[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {ja_p[3]}]

##Pmod Header JB
##IO_L15N_T2_DQS_34
#set_property PACKAGE_PIN U20 [get_ports {jb_n[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jb_n[0]}]

##IO_L15P_T2_DQS_34
#set_property PACKAGE_PIN T20 [get_ports {jb_p[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jb_p[0]}]

##IO_L16N_T2_34
#set_property PACKAGE_PIN W20 [get_ports {jb_n[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jb_n[1]}]

##IO_L16P_T2_34
#set_property PACKAGE_PIN V20 [get_ports {jb_p[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jb_p[1]}]

##IO_L17N_T2_34
#set_property PACKAGE_PIN Y19 [get_ports {jb_n[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jb_n[2]}]

##IO_L17P_T2_34
#set_property PACKAGE_PIN Y18 [get_ports {jb_p[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jb_p[2]}]

##IO_L22N_T3_34
#set_property PACKAGE_PIN W19 [get_ports {jb_n[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jb_n[3]}]

##IO_L22P_T3_34
#set_property PACKAGE_PIN W18 [get_ports {jb_p[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jb_p[3]}]

##Pmod Header JC
##IO_L10N_T1_34
#set_property PACKAGE_PIN W15 [get_ports {jc_n[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jc_n[0]}]

##IO_L10P_T1_34
#set_property PACKAGE_PIN V15 [get_ports {jc_p[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jc_p[0]}]

##IO_L1N_T0_34
#set_property PACKAGE_PIN T10 [get_ports {jc_n[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jc_n[1]}]

##IO_L1P_T0_34
#set_property PACKAGE_PIN T11 [get_ports {jc_p[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jc_p[1]}]

##IO_L8N_T1_34
#set_property PACKAGE_PIN Y14 [get_ports {jc_n[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jc_n[2]}]

##IO_L8P_T1_34
#set_property PACKAGE_PIN W14 [get_ports {jc_p[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jc_p[2]}]

##IO_L2N_T0_34
#set_property PACKAGE_PIN U12 [get_ports {jc_n[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jc_n[3]}]

##IO_L2P_T0_34
#set_property PACKAGE_PIN T12 [get_ports {jc_p[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jc_p[3]}]

##Pmod Header JD
##IO_L5N_T0_34
#set_property PACKAGE_PIN T15 [get_ports {jd_n[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jd_n[0]}]

##IO_L5P_T0_34
#set_property PACKAGE_PIN T14 [get_ports {jd_p[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jd_p[0]}]

##IO_L6N_T0_VREF_34
#set_property PACKAGE_PIN R14 [get_ports {jd_n[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jd_n[1]}]

##IO_L6P_T0_34
#set_property PACKAGE_PIN P14 [get_ports {jd_p[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jd_p[1]}]

##IO_L11N_T1_SRCC_34
#set_property PACKAGE_PIN U15 [get_ports {jd_n[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jd_n[2]}]

##IO_L11P_T1_SRCC_34
#set_property PACKAGE_PIN U14 [get_ports {jd_p[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jd_p[2]}]

##IO_L21N_T3_DQS_34
#set_property PACKAGE_PIN V18 [get_ports {jd_n[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jd_n[3]}]

##IO_L21P_T3_DQS_34
#set_property PACKAGE_PIN V17 [get_ports {jd_p[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {jd_p[3]}]

##Pmod Header JE
##IO_L4P_T0_34
set_property PACKAGE_PIN V12 [get_ports {ctrl_btns[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ctrl_btns[0]}]

##IO_L18N_T2_34
set_property PACKAGE_PIN W16 [get_ports {ctrl_btns[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ctrl_btns[1]}]

##IO_25_35
set_property PACKAGE_PIN J15 [get_ports {ctrl_btns[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ctrl_btns[2]}]

##IO_L19P_T3_35
set_property PACKAGE_PIN H15 [get_ports {ctrl_btns[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ctrl_btns[3]}]

##IO_L3N_T0_DQS_34
set_property PACKAGE_PIN V13 [get_ports {ctrl_btns[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ctrl_btns[4]}]

##IO_L9N_T1_DQS_34
#set_property PACKAGE_PIN U17 [get_ports {je[5]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {je[5]}]

##IO_L20P_T3_34
#set_property PACKAGE_PIN T17 [get_ports {je[6]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {je[6]}]

##IO_L7N_T1_34
#set_property PACKAGE_PIN Y17 [get_ports {je[7]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {je[7]}]


##USB-OTG overcurrent detect pin
##IO_L3P_T0_DQS_PUDC_B_34
#set_property PACKAGE_PIN U13 [get_ports otg_oc]
#set_property IOSTANDARD LVCMOS33 [get_ports otg_oc]


##VGA Connector
##IO_L7P_T1_AD2P_35
#set_property PACKAGE_PIN M19 [get_ports {vga_r[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_r[0]}]

##IO_L9N_T1_DQS_AD3N_35
#set_property PACKAGE_PIN L20 [get_ports {vga_r[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_r[1]}]

##IO_L17P_T2_AD5P_35
#set_property PACKAGE_PIN J20 [get_ports {vga_r[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_r[2]}]

##IO_L18N_T2_AD13N_35
#set_property PACKAGE_PIN G20 [get_ports {vga_r[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_r[3]}]

##IO_L15P_T2_DQS_AD12P_35
#set_property PACKAGE_PIN F19 [get_ports {vga_r[4]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_r[4]}]

##IO_L14N_T2_AD4N_SRCC_35
#set_property PACKAGE_PIN H18 [get_ports {vga_g[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_g[0]}]

##IO_L14P_T2_SRCC_34
#set_property PACKAGE_PIN N20 [get_ports {vga_g[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_g[1]}]

##IO_L9P_T1_DQS_AD3P_35
#set_property PACKAGE_PIN L19 [get_ports {vga_g[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_g[2]}]

##IO_L10N_T1_AD11N_35
#set_property PACKAGE_PIN J19 [get_ports {vga_g[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_g[3]}]

##IO_L17N_T2_AD5N_35
#set_property PACKAGE_PIN H20 [get_ports {vga_g[4]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_g[4]}]

##IO_L15N_T2_DQS_AD12N_35
#set_property PACKAGE_PIN F20 [get_ports {vga_g[5]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_g[5]}]

##IO_L14N_T2_SRCC_34
#set_property PACKAGE_PIN P20 [get_ports {vga_b[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_b[0]}]

##IO_L7N_T1_AD2N_35
#set_property PACKAGE_PIN M20 [get_ports {vga_b[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_b[1]}]

##IO_L10P_T1_AD11P_35
#set_property PACKAGE_PIN K19 [get_ports {vga_b[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_b[2]}]

##IO_L14P_T2_AD4P_SRCC_35
#set_property PACKAGE_PIN J18 [get_ports {vga_b[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_b[3]}]

##IO_L18P_T2_AD13P_35
#set_property PACKAGE_PIN G19 [get_ports {vga_b[4]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {vga_b[4]}]

##IO_L13N_T2_MRCC_34
#set_property PACKAGE_PIN P19 [get_ports vga_hs]
#set_property IOSTANDARD LVCMOS33 [get_ports vga_hs]

##IO_0_34
#set_property PACKAGE_PIN R19 [get_ports vga_vs]
#set_property IOSTANDARD LVCMOS33 [get_ports vga_vs]

