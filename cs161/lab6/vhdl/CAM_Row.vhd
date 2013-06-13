

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity CAM_Row is
		Generic (CAM_WIDTH : integer := 32) ;
		Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           row_match : out  STD_LOGIC);
end CAM_Row;

architecture Behavioral of CAM_Row is


component CAM_Cell is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
end component ;

constant num_one : std_logic := '1';
signal row_bits : std_logic_vector( CAM_WIDTH-1 downto 0);
for all : CAM_Cell use entity work.CAM_Cell(Ternary_at_Input_Cell); 


begin

		start : CAM_CELL
			port map ( 
			  clk => clk,
           rst => rst,
           we => we,
           cell_search_bit => search_word(0),
			  cell_match_bit_in => num_one,
           cell_match_bit_out => row_bits(0)
				);

		gen_sub : for N in 1 to CAM_WIDTH-1 generate
			forward_unit : CAM_CELL
				port map (
			  clk => clk,
           rst => rst,
           we => we,
           cell_search_bit => search_word(N),
			  cell_match_bit_in => row_bits(N-1),
           cell_match_bit_out => row_bits(N)
					);
		end generate gen_sub;

		row_match <= row_bits(CAM_WIDTH-1);

end Behavioral;









