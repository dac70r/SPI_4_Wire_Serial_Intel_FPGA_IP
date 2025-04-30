module 

spi(
	input clk,
	input	reset_n,									// pin_L7
	output led,										// pin_D15
	output unused_pin_l6,						// pin_L6
	output led_nios,								// pin_M6
	
	// esc
	output esc_sclk_pin_m2,						// pin_M2
	output esc_ss_n_pin_m1,						// pin_M1
	output esc_cs_export_pin_m4,				// pin_M4
	output esc_mosi_pin_m3,						// pin_M3
	input	 esc_miso_pin_n2,						// pin_N2
	input  esc_eepdone_input_export_pin_n1, // pin_N1
	input	 reserved_reset_n,					// pin_L7 (not assigned)
	output unused_pin_p2,						// pin_P2
	output unused_pin_p1,						// pin_P1
	output unused_pin_r2							// pin_R2
);

// Heartbeat Instantiation
heartbeat_ip #(.TICKS(25_000_000)) u0
(
	.clk(clk),
	.output_led(led)
);

// NIOS II Instantiation
spi_platform_designer u1 (
		.clk_clk(clk),                  										//               clk.clk
		.esc_eepdone_input_export(esc_eepdone_input_export_pin_n1), // esc_eepdone_input.export
		.esc_spi_MISO(esc_miso_pin_n2),             						//           esc_spi.MISO
		.esc_spi_MOSI(esc_mosi_pin_m3),             						//                  .MOSI
		.esc_spi_SCLK(esc_sclk_pin_m2),            					 	//                  .SCLK
		.esc_spi_SS_n(esc_ss_n_pin_m1),             						//                  .SS_n
		.esc_spi_cs_export(esc_cs_export_pin_m4),        				//        esc_spi_cs.export
		.led_export(led_nios),               								//               led.export
		.reset_reset_n(reset_n)            									//             reset.reset_n
	);
	
	
assign unused_pin_p2 = 1'b1;						// pin_P2
assign unused_pin_p1 = 1'b1;						// pin_P1
assign unused_pin_r2	= 1'b1;						// pin_R2

endmodule