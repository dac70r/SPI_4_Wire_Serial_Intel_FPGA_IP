
module spi_platform_designer (
	clk_clk,
	reset_reset_n,
	spi_pin_MISO,
	spi_pin_MOSI,
	spi_pin_SCLK,
	spi_pin_SS_n,
	spi_ss_manual_export);	

	input		clk_clk;
	input		reset_reset_n;
	input		spi_pin_MISO;
	output		spi_pin_MOSI;
	output		spi_pin_SCLK;
	output		spi_pin_SS_n;
	output		spi_ss_manual_export;
endmodule
