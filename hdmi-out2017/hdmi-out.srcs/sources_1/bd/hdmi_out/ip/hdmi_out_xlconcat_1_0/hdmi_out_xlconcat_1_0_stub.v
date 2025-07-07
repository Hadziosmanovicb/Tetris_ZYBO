// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2018.2 (win64) Build 2258646 Thu Jun 14 20:03:12 MDT 2018
// Date        : Tue Jan 21 15:27:39 2025
// Host        : Benjo running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub -rename_top hdmi_out_xlconcat_1_0 -prefix
//               hdmi_out_xlconcat_1_0_ hdmi_out_xlconcat_1_0_stub.v
// Design      : hdmi_out_xlconcat_1_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z010clg400-1
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "xlconcat_v2_1_1_xlconcat,Vivado 2018.2" *)
module hdmi_out_xlconcat_1_0(In0, In1, dout)
/* synthesis syn_black_box black_box_pad_pin="In0[3:0],In1[4:0],dout[8:0]" */;
  input [3:0]In0;
  input [4:0]In1;
  output [8:0]dout;
endmodule
