-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2018.2 (win64) Build 2258646 Thu Jun 14 20:03:12 MDT 2018
-- Date        : Tue Jan 21 15:27:39 2025
-- Host        : Benjo running 64-bit major release  (build 9200)
-- Command     : write_vhdl -force -mode funcsim -rename_top hdmi_out_xlconcat_1_0 -prefix
--               hdmi_out_xlconcat_1_0_ hdmi_out_xlconcat_1_0_sim_netlist.vhdl
-- Design      : hdmi_out_xlconcat_1_0
-- Purpose     : This VHDL netlist is a functional simulation representation of the design and should not be modified or
--               synthesized. This netlist cannot be used for SDF annotated simulation.
-- Device      : xc7z010clg400-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity hdmi_out_xlconcat_1_0 is
  port (
    In0 : in STD_LOGIC_VECTOR ( 3 downto 0 );
    In1 : in STD_LOGIC_VECTOR ( 4 downto 0 );
    dout : out STD_LOGIC_VECTOR ( 8 downto 0 )
  );
  attribute NotValidForBitStream : boolean;
  attribute NotValidForBitStream of hdmi_out_xlconcat_1_0 : entity is true;
  attribute CHECK_LICENSE_TYPE : string;
  attribute CHECK_LICENSE_TYPE of hdmi_out_xlconcat_1_0 : entity is "hdmi_out_xlconcat_1_0,xlconcat_v2_1_1_xlconcat,{}";
  attribute DowngradeIPIdentifiedWarnings : string;
  attribute DowngradeIPIdentifiedWarnings of hdmi_out_xlconcat_1_0 : entity is "yes";
  attribute X_CORE_INFO : string;
  attribute X_CORE_INFO of hdmi_out_xlconcat_1_0 : entity is "xlconcat_v2_1_1_xlconcat,Vivado 2018.2";
end hdmi_out_xlconcat_1_0;

architecture STRUCTURE of hdmi_out_xlconcat_1_0 is
  signal \^in0\ : STD_LOGIC_VECTOR ( 3 downto 0 );
  signal \^in1\ : STD_LOGIC_VECTOR ( 4 downto 0 );
begin
  \^in0\(3 downto 0) <= In0(3 downto 0);
  \^in1\(4 downto 0) <= In1(4 downto 0);
  dout(8 downto 4) <= \^in1\(4 downto 0);
  dout(3 downto 0) <= \^in0\(3 downto 0);
end STRUCTURE;
