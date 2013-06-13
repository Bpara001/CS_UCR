--##############################
--Names: Hans Wun, Chris Wong
--Login: wunh, wongc
--Email: hwun001@ucr.edu, wongc@cs.ucr.edu
--Lab Section: 022
--Assignment: Lab 7
--I acknowledge all content is original.
--##############################

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity mux_5 is 
	port(
	sel : in std_logic_vector( 2 downto 0 );
	input : in std_logic_vector(4 downto 0);
	output : out std_logic
	);
end mux_5;

architecture behavior of mux_5 is
begin
	with sel select output <=
		input(0) when "000",
		input(1) when "001",
		input(2) when "010",
		input(3) when "011",
		input(4) when others;
end behavior;
