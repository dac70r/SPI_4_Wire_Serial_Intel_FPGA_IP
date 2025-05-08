	spi_platform_designer u0 (
		.clk_clk                  (<connected-to-clk_clk>),                  //               clk.clk
		.esc_eepdone_input_export (<connected-to-esc_eepdone_input_export>), // esc_eepdone_input.export
		.esc_spi_MISO             (<connected-to-esc_spi_MISO>),             //           esc_spi.MISO
		.esc_spi_MOSI             (<connected-to-esc_spi_MOSI>),             //                  .MOSI
		.esc_spi_SCLK             (<connected-to-esc_spi_SCLK>),             //                  .SCLK
		.esc_spi_SS_n             (<connected-to-esc_spi_SS_n>),             //                  .SS_n
		.esc_spi_cs_export        (<connected-to-esc_spi_cs_export>),        //        esc_spi_cs.export
		.esc_spi_sint_export      (<connected-to-esc_spi_sint_export>),      //      esc_spi_sint.export
		.led_export               (<connected-to-led_export>),               //               led.export
		.reset_reset_n            (<connected-to-reset_reset_n>)             //             reset.reset_n
	);

