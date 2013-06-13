
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity CAM_Cell is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
end CAM_Cell;

architecture Binary_Cell of CAM_Cell is

	COMPONENT myFF 
    port(C, D, we, rst : in std_logic;
         Q    : out std_logic);
	end COMPONENT;
	
	signal Q : std_logic;
begin
	ffd:   myFF port map(
				C => clk,
				D => cell_search_bit,
				we => we,
				rst =>rst,
				Q => Q
				);
	 process (clk)
    begin
        if (clk'event and clk='1') then
				cell_match_bit_out <= cell_match_bit_in and  ( cell_search_bit xnor Q ) ;
        end if;
    end process;

end Binary_Cell ;







