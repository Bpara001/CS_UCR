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

entity dpd_to_bcd is
	port(
		b	: in std_logic_vector(9 downto 0);
		d0	: out std_logic_vector(3 downto 0);
		d1	: out std_logic_vector(3 downto 0);
		d2	: out std_logic_vector(3 downto 0)
	);
end dpd_to_bcd;

architecture Behavioral of dpd_to_bcd is

	signal d0_sig 	: std_logic_vector( 3 downto 0 );
	signal d1_sig	: std_logic_vector( 3 downto 0 );
	signal d2_sig	: std_logic_vector( 3 downto 0 );
	
begin
	process( b )
		begin
			if( b(3) = '0' ) then
				d0_sig <= "0" & b( 2 downto 0 );
				d1_sig <= "0" & b( 6 downto 4 );
				d2_sig <= "0" & b( 9 downto 7 );
			elsif( b( 3 downto 1 ) = "100" ) then
				d0_sig <= "100" & b(0);
				d1_sig <= "0" & b( 6 downto 4 );
				d2_sig <= "0" & b( 9 downto 7 );
			elsif( b( 3 downto 1 ) = "101" ) then
				d0_sig <= "0" & b( 6 downto 5 ) & b( 0 );
				d1_sig <= "100" & b( 4 );
				d2_sig <= "0" & b( 9 downto 7 );
			elsif( b( 3 downto 1 ) = "110" ) then
				d0_sig <= "0" & b( 9 downto 8 ) & b( 0 );
				d1_sig <= "0" & b( 6 downto 4 );
				d2_sig <= "100" & b( 7 );
			elsif( b( 3 downto 1 ) = "111" and b( 6 downto 5 ) = "10" ) then
				d0_sig <= "100" & b( 0 );
				d1_sig <= "100" & b( 4 );
				d2_sig <= "0" & b( 9 downto 7 );
			elsif( b( 3 downto 1 ) = "111" and b( 6 downto 5 ) = "01" ) then
				d0_sig <= "100" & b( 0 );
				d1_sig <= "0" & b( 9 downto 8 ) & b( 4 );
				d2_sig <= "100" & b( 7 );
			elsif( b( 3 downto 1 ) = "111" and b( 6 downto 5 ) = "00" ) then
				d0_sig <= "0" & b( 9 downto 8 ) & b( 0 );
				d1_sig <= "100" & b( 4 );
				d2_sig <= "100" & b( 7 );
			elsif( b( 3 downto 1 ) = "111" and b( 6 downto 5 ) = "11" ) then
				d0_sig <= "100" & b( 0 );
				d1_sig <= "100" & b( 4 );
				d2_sig <= "100" & b( 7 );
			else
				d0_sig <= "0000";
				d1_sig <= "0000";
				d2_sig <= "0000";
			end if;
		end process;

		d0 <= d0_sig;
		d1 <= d1_sig;
		d2 <= d2_sig;
		
end Behavioral;

