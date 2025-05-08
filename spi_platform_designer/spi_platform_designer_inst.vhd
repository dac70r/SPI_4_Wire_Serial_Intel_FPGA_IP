	component spi_platform_designer is
		port (
			clk_clk                  : in  std_logic := 'X'; -- clk
			esc_eepdone_input_export : in  std_logic := 'X'; -- export
			esc_spi_MISO             : in  std_logic := 'X'; -- MISO
			esc_spi_MOSI             : out std_logic;        -- MOSI
			esc_spi_SCLK             : out std_logic;        -- SCLK
			esc_spi_SS_n             : out std_logic;        -- SS_n
			esc_spi_cs_export        : out std_logic;        -- export
			esc_spi_sint_export      : in  std_logic := 'X'; -- export
			led_export               : out std_logic;        -- export
			reset_reset_n            : in  std_logic := 'X'  -- reset_n
		);
	end component spi_platform_designer;

	u0 : component spi_platform_designer
		port map (
			clk_clk                  => CONNECTED_TO_clk_clk,                  --               clk.clk
			esc_eepdone_input_export => CONNECTED_TO_esc_eepdone_input_export, -- esc_eepdone_input.export
			esc_spi_MISO             => CONNECTED_TO_esc_spi_MISO,             --           esc_spi.MISO
			esc_spi_MOSI             => CONNECTED_TO_esc_spi_MOSI,             --                  .MOSI
			esc_spi_SCLK             => CONNECTED_TO_esc_spi_SCLK,             --                  .SCLK
			esc_spi_SS_n             => CONNECTED_TO_esc_spi_SS_n,             --                  .SS_n
			esc_spi_cs_export        => CONNECTED_TO_esc_spi_cs_export,        --        esc_spi_cs.export
			esc_spi_sint_export      => CONNECTED_TO_esc_spi_sint_export,      --      esc_spi_sint.export
			led_export               => CONNECTED_TO_led_export,               --               led.export
			reset_reset_n            => CONNECTED_TO_reset_reset_n             --             reset.reset_n
		);

