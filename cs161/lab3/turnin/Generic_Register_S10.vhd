--Names: Hans Wun, Chris Wong
--Login: wunh, wongc
--Email: hwun001@ucr.edu, wongc@cs.ucr.edu
--Lab Section: 0##
--##############################################################################
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Generic_Register is
	generic ( NUMBITS : integer := 32) ;
	port(
		rst   : in std_logic;
      clk   : in std_logic;
      load : in std_logic;
      input : in std_logic_vector (NUMBITS-1 downto 0);
      output: out std_logic_vector (NUMBITS-1 downto 0));
end Generic_Register ;

architecture Behavioral of Generic_Register is

constant zeros : STD_LOGIC_VECTOR(NUMBITS-1 DOWNTO 0) := (others => '0') ;

begin

	process(rst, clk, input, load)
		begin
			if( rst = '1' ) then
				output <= zeros ;
			elsif( clk = '1' and clk'event and load = '1' )then
				output <= input ;
			end if;
	end process;

end Behavioral;
