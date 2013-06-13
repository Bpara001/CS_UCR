----------------------------------------------------------------------------------
-- Name: Chris Wong, Hans Wun
-- CS161 Lab 3
--
--
--
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.all;
use work.MIPS_LIB.all;


entity Mux_32_2_1 is
    Port ( input_a : in  STD_LOGIC_VECTOR(31 downto 0);
           input_b : in  STD_LOGIC_VECTOR(31 downto 0);
           output : out  STD_LOGIC_VECTOR(31 downto 0);
           sel : in  STD_LOGIC
			 );
end Mux_32_2_1;

architecture Behavioral of Mux_32_2_1 is

begin
		
		process(sel, input_a, input_b)
		begin
			if(sel = '0') THEN
				output <= input_a;
		
			elsif (sel = '1') THEN
				output <= input_b;
		
			else
				null;

			end if;
		end process;
end Behavioral;

--====================
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.all;
use work.MIPS_LIB.all;

entity Mux_32_3_1 is
    Port ( input_a : in  STD_LOGIC_VECTOR(31 downto 0);
           input_b : in  STD_LOGIC_VECTOR(31 downto 0);
			  input_c : in STD_LOGIC_VECTOR(31 downto 0);
           output : out  STD_LOGIC_VECTOR(31 downto 0);
           sel : in  STD_LOGIC_VECTOR(1 downto 0)
			 );
end Mux_32_3_1;

architecture Behavioral of Mux_32_3_1 is

begin

		process(sel, input_a, input_b, input_c)
		begin
			if(sel = "00")  THEN
				output <= input_a;
		
			elsif (sel = "01") THEN
				output <= input_b;
		
			elsif (sel = "10") THEN
				output <= input_c;
			
			else
				null;
			
			end if;
			
		end process;

end Behavioral;

--=====================
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.all;
use work.MIPS_LIB.all;

entity Mux_32_4_1 is
    Port ( input_a : in  STD_LOGIC_VECTOR(31 downto 0);
           input_b : in  STD_LOGIC_VECTOR(31 downto 0);
			  input_c : in  STD_LOGIC_VECTOR(31 downto 0);
			  input_d : in  STD_LOGIC_VECTOR(31 downto 0);
           output : out  STD_LOGIC_VECTOR(31 downto 0);
           sel : in  STD_LOGIC_VECTOR(1 downto 0)
			);
end Mux_32_4_1;

architecture Behavioral of Mux_32_4_1 is

begin

		process(sel, input_a, input_b, input_c, input_d)
		begin
			if(sel = "00")  THEN
				output <= input_a;
		
			elsif (sel = "01") THEN
				output <= input_b;
		
			elsif (sel = "10") THEN
				output <= input_c;
				
			elsif (sel = "11") THEN
				output <= input_d;
			
			else
				null;

			end if;
			
		end process;
end Behavioral;

--=======================
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.all;
use work.MIPS_LIB.all;

entity Mux_5_2_1 is
    Port ( input_a : in  STD_LOGIC_VECTOR(4 downto 0);
           input_b : in  STD_LOGIC_VECTOR(4 downto 0);
           output : out  STD_LOGIC_VECTOR(4 downto 0);
           sel : in  STD_LOGIC
         );
end Mux_5_2_1;

architecture Behavioral of Mux_5_2_1 is

begin

		process(sel, input_a, input_b)
		begin
		
			if(sel = '0')  THEN
				output <= input_a;
			
			elsif (sel = '1') THEN
				output <= input_b;

			else
				null;
				
			end if;
		
		end process;
end Behavioral;

