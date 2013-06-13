----------------------------------------------------------------------
--Names: James Fang, Chris Wong
--Login: jfang003, wongc
--Email: jfang003@ucr.edu, cwong030@ucr.edu
--Lab Section: 0##
--Assignment: Lab #2
--I acknowledge all content is original.
---------------------------------------------------------------------

--Load libraries
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_BIT.ALL;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

--Declare enity with its inputs and outputs
entity lab2_vhdl is
    Port ( floating : in  STD_LOGIC_vector(31 downto 0);
           fixed : out  STD_LOGIC_vector(31 downto 0)
			  );
end lab2_vhdl;

--Declare signals ('wires') 
architecture Behavioral of lab2_vhdl is
signal flag: std_logic;
signal exponent: std_logic_vector(7 downto 0);
signal exponent1: std_logic_vector(7 downto 0);
signal exponent2: std_logic_vector(7 downto 0);
signal man: std_logic_vector(23 downto 0);
constant val: std_logic_vector(7 downto 0) := "10000111";
signal temp_sig: std_logic;
signal result: std_logic_vector(31 downto 0);
signal result2: std_logic_vector(31 downto 0);
signal shifts: integer;
constant ZEROS: std_logic_vector(31 downto 0) := (others => '0');

begin

--Process #1: chop up the input into sign flag, exponenet, and man.
extract: process(floating)
	begin
		if(floating(31)='1') then --Set the sign flag to t/f
			flag <= '1';
		else 
			flag <= '0';
		end if;
		--set shift right
		exponent1 <= val - floating(30 downto 23);
		--set shift left
		exponent2 <= floating(30 downto 23) - val;
		man <= "1" & floating(22 downto 0);	--set mantissa
		
end process;

--Process #2: figure out to shift either left or right
compute:process(exponent1, exponent2)
	begin
		if(exponent1(7)='1') then
			temp_sig <= '1';
			shifts <= conv_integer(exponent2);--set left shift
		else
			temp_sig <= '0';
			shifts <= conv_integer(exponent1);--set right shift
		end if;
		
end process;

--Process #3: shift the mantissa the correct direction and amount
shift:process(shifts,man,temp_sig)
	begin
		result <= ZEROS;
		if(shifts > 23) then	--right shift overload
			result <= ZEROS;
		elsif(shifts <= 23 and temp_sig = '0') then  --right shift
			result <=  ZEROS(7 downto 0) & ZEROS((shifts-1) 
					downto 0) & man(23 downto shifts);
		elsif(shifts >= 6 and temp_sig = '1') then --left shift
			result <= '0' & man((30-shifts) downto 0) 
					   & ZEROS((shifts-1) downto 0);
		elsif(shifts < 6 and temp_sig = '1') then  --left shift
			result <=  ZEROS(7 downto shifts) & 
				man(23 downto 0) & ZEROS(shifts downto 1);
		else
		end if;

end process;

--Process #4: convert to negative if necessary
flip:process(result,flag)
begin
	if(flag = '1') then
		result2 <= (not result) + 1;	--not(result) + 1
	else
		result2 <= result;
	end if;
	
end process;

fixed <= result2;--assign temporary signal to the output port

end Behavioral;

