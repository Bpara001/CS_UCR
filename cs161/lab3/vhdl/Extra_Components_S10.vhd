-------------------------------------------------------------------------------
-- Sign Extend Unit
-------------------------------------------------------------------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all; 
use work.MIPS_LIB.all;

entity SignExt_16_32 is
    port(
	input	: in std_logic_vector(15 downto 0);
	output	: out std_logic_vector(31 downto 0)
	);
end SignExt_16_32;

architecture bhv of SignExt_16_32 is
begin

	output(31 downto 16) <= (others => input(15)) ;
	output(15 downto 0) <= input(15 downto 0) ;

end bhv;
