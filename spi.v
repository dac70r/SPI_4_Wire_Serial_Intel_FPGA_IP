module 

spi(
	input clk,
	input	reset_n,
	
	output led
);

// Heartbeat Instantiation
heartbeat_ip #(.TICKS(25_000_000)) u0
(
	.clk(clk),
	.output_led(led)
);

endmodule