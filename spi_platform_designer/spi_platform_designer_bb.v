
module spi_platform_designer (
	clk_clk,
	esc_eepdone_input_export,
	esc_spi_MISO,
	esc_spi_MOSI,
	esc_spi_SCLK,
	esc_spi_SS_n,
	esc_spi_cs_export,
	led_export,
	reset_reset_n);	

	input		clk_clk;
	input		esc_eepdone_input_export;
	input		esc_spi_MISO;
	output		esc_spi_MOSI;
	output		esc_spi_SCLK;
	output		esc_spi_SS_n;
	output		esc_spi_cs_export;
	output		led_export;
	input		reset_reset_n;
endmodule
