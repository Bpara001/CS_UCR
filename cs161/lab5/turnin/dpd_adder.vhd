----------------------------------------------------------------------------------
--Names: Chris Wong , Allen Yu
--Login:  wongc, yua
--Email: cwong030@student.ucr.edu , yua@cs.ucr.edu
--Lab Section: 022
--Assignment: Lab 5
--I acknowledge all content is original.
----------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity bcd_full_adder is
	port(
		val_1		: in std_logic_vector(3 downto 0);
		val_2		: in std_logic_vector(3 downto 0);
		c_in		: in std_logic;
		
		result	: out std_logic_vector(3 downto 0);
		c_out		: out std_logic
	);
end bcd_full_adder;

architecture Behavioral of bcd_full_adder is
signal result_sig 	: std_logic_vector( 3 downto 0 );
	signal c_out_sig			: std_logic;
	signal c_in_temp 		: std_logic_vector(3 downto 0);
	constant weird		: std_logic_vector(2 downto 0) := "000";
	
begin


	c_in_temp <= weird & c_in;



	adding: process(val_1,val_2, c_in_temp )
		begin	
			result_sig <= val_1 + val_2 + c_in_temp;
		end process;
		
	carryout: process(result_sig)
		begin
			if(result_sig = "1010" or result_sig = "1011" or result_sig = "1100" or result_sig = "1101" or result_sig = "1110" or result_sig = "1111") then
					c_out_sig <= '1';
					result <= result_sig - "1010";
				else
					c_out_sig <= '0';	
					result <= result_sig;
			end if;
		end process;

	
	c_out <= c_out_sig;
		
end Behavioral;





-- DO NOT MODIFY BELOW THIS LINE
-- ---------- ---------- --------- ---------- ---------- ----------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity bcd_3_digit_adder is
	port(
		val_1	: in std_logic_vector(11 downto 0);
		val_2 : in std_logic_vector(11 downto 0);
		c_in	: in std_logic;
		
		result	: out std_logic_vector(11 downto 0);
		c_out		: out	std_logic
	);
end bcd_3_digit_adder;

architecture Behavioral of bcd_3_digit_adder is

	component bcd_full_adder is
		port(
			val_1 : IN  std_logic_vector(3 downto 0);
			val_2 : IN  std_logic_vector(3 downto 0);
			c_in : IN  std_logic;
			result : OUT  std_logic_vector(3 downto 0);
			c_out : OUT  std_logic
		);
	end component;
	
	signal ripple : std_logic_vector(1 downto 0);
begin

	lst_sig: bcd_full_adder port map(
		val_1 => val_1(3 downto 0),
		val_2 => val_2(3 downto 0),
		c_in	=> c_in,
		result	=> result(3 downto 0),
		c_out	=> ripple(0)
	);

	middle: bcd_full_adder port map(
		val_1 => val_1(7 downto 4),
		val_2 => val_2(7 downto 4),
		c_in	=> ripple(0),
		result	=> result(7 downto 4),
		c_out	=> ripple(1)
	);
	
	mst_sig: bcd_full_adder port map(
		val_1 => val_1(11 downto 8),
		val_2 => val_2(11 downto 8),
		c_in	=> ripple(1),
		result	=> result(11 downto 8),
		c_out	=> c_out
	);
	
end Behavioral;






library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity dpd_adder is
	port(
		dpd_val_1	: in std_logic_vector(9 downto 0);
		dpd_val_2	: in std_logic_vector(9 downto 0);
		c_in			: in std_logic;
		bcd_result	: out std_logic_vector(11 downto 0);
		c_out			: out std_logic
	);
end dpd_adder;

architecture Behavioral of dpd_adder is

	component dpd_to_bcd is
		port(
			b	: in std_logic_vector(9 downto 0);
			d0	: out std_logic_vector(3 downto 0);
			d1	: out std_logic_vector(3 downto 0);
			d2	: out std_logic_vector(3 downto 0)
		);
	end component;

	component bcd_3_digit_adder is
		port(
			val_1 : IN  std_logic_vector(11 downto 0);
         val_2 : IN  std_logic_vector(11 downto 0);
         c_in : IN  std_logic;
         result : OUT  std_logic_vector(11 downto 0);
         c_out : OUT  std_logic
		);
	end component;
	
	signal val_1_d0 : std_logic_vector(3 downto 0);
	signal val_1_d1 : std_logic_vector(3 downto 0);
	signal val_1_d2 : std_logic_vector(3 downto 0);
	signal bcd_val_1 : std_logic_vector(11 downto 0);
	
	signal val_2_d0 : std_logic_vector(3 downto 0);
	signal val_2_d1 : std_logic_vector(3 downto 0);
	signal val_2_d2 : std_logic_vector(3 downto 0);
	signal bcd_val_2 : std_logic_vector(11 downto 0);
	
begin

	dpd1: dpd_to_bcd port map(
		b => dpd_val_1,
		d0 => val_1_d0,
		d1 => val_1_d1,
		d2 => val_1_d2
	);
	
	dpd2: dpd_to_bcd port map(
		b => dpd_val_2,
		d0 => val_2_d0,
		d1 => val_2_d1,
		d2 => val_2_d2
	);

	bcd_val_1 <= val_1_d2 & val_1_d1 & val_1_d0;
	bcd_val_2 <= val_2_d2 & val_2_d1 & val_2_d0;
	
	adder: bcd_3_digit_adder port map(
		val_1 => bcd_val_1,
		val_2 => bcd_val_2,
		c_in	=> c_in,
		result => bcd_result,
		c_out	=> c_out
	);
	
end Behavioral;

