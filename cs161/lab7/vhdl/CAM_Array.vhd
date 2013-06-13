

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;



entity CAM_Array is
	Generic (CAM_WIDTH : integer := 8 ;
				CAM_DEPTH : integer := 4 ) ;
	Port (  clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
			  we_decoded_row_address : in STD_LOGIC_VECTOR(CAM_DEPTH-1 downto 0) ;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           decoded_match_address : out  STD_LOGIC_VECTOR (CAM_DEPTH-1 downto 0);
			  decoder_sig : in STD_LOGIC;
			  control_update_sig : in STD_LOGIC
			  
			  
			  );
			  
end CAM_Array;

architecture Behavioral of CAM_Array is

component CAM_Row is
	Generic (CAM_WIDTH : integer := 8) ;
	Port (  clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           row_match : out  STD_LOGIC);
end component ;


begin

-- Connect the CAM rows here
	gen_sub : for N in 0 to CAM_DEPTH-1 generate
			forward_unit : CAM_ROW
				port map (
			  clk => clk,
           rst => rst,
           we => we_decoded_row_address(N),
           search_word => search_word,
           row_match => decoded_match_address(N)
				);
				
		end generate gen_sub;

end Behavioral;

