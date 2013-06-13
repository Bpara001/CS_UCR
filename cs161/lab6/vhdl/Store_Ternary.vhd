
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity CAM_Cell3 is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
           cell_dont_care_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
end CAM_Cell3;

architecture Stored_Ternary_Cell of CAM_Cell3 is

	COMPONENT myFF 
    port(C, D, we, rst : in std_logic;
         Q    : out std_logic);
	end COMPONENT;	
	
	
	signal Q2 : std_logic;
	signal Q : std_logic;
begin
	ffd:   myFF port map(
				C => clk,
				D => cell_search_bit,
				we => we,
				rst =>rst,
				Q => Q
				);
	ffd2:   myFF port map(
				C => clk,
				D => cell_dont_care_bit,
				we => we,
				rst =>rst,
				Q => Q2
				);
	 process (clk)
    begin
        if (clk'event and clk='1') then
				cell_match_bit_out <= cell_match_bit_in and ( Q2 or ( cell_search_bit xnor Q ) );
        end if;
    end process;

end Stored_Ternary_Cell ;







