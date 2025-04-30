module 

heartbeat_ip #(parameter TICKS = 25_000_000)
(
	input clk,
	output output_led
);

reg [31:0] count = 32'b0;
reg led_output = 1'b1;				// assuming led is active low

always @ (posedge clk)
begin 
	if(count >= TICKS)
	begin 
		count <= 32'b0;
		led_output <= ~led_output;
	end
	else begin count <= count + 1; end
end

assign output_led = led_output; 

endmodule