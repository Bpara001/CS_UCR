--Names: Hans Wun, Chris Wong
--Login: wunh, wongc
--Email: hwun001@ucr.edu, wongc@cs.ucr.edu
--Lab Section: 0##
--Assignment: Lab #1
--I acknowledge all content is original.
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_unsigned.all;
use ieee.std_logic_arith.all;

entity my_alu is
		generic(
			NUMBITS	: natural	:= 4
		);
		Port ( 
				A : in  STD_LOGIC_VECTOR(NUMBITS-1 downto 0);
				B : in  STD_LOGIC_VECTOR(NUMBITS-1 downto 0);
				opcode : in  STD_LOGIC_VECTOR(2 downto 0);
				result : out  STD_LOGIC_VECTOR(NUMBITS-1 downto 0);
				carryout : out  STD_LOGIC;
				overflow : out  STD_LOGIC;
				zero : out  STD_LOGIC
		);
end my_alu;

architecture Behavioral of my_alu is

constant ZEROS : STD_LOGIC_VECTOR(NUMBITS-1 downto 0):= (others =>'0');
--Inputs
signal tempA_sig : STD_LOGIC_VECTOR(NUMBITS downto 0);
signal tempB_sig : STD_LOGIC_VECTOR(NUMBITS downto 0);
--Outputs
signal result_sig : STD_LOGIC_VECTOR(NUMBITS downto 0);
signal carry_sig : STD_LOGIC;
signal overflow_sig : STD_LOGIC;
signal zero_sig : STD_LOGIC;

begin

--First, sign extend when approiate and put them into tempA 
sign_extend:process(A , B)
	
	begin
	
			if ( A >= 0 ) then
				tempA_sig <= ('0' & A );
			else
				tempA_sig <= ('1' & A );
			end if;
			
			if ( B >= 0 ) then
				tempB_sig <= ('0' & B );
			else
				tempB_sig <= ('1' & B );
			end if;
	
	end process;

--Find out the raw 'result' and put it into result_sig
evaluate_pr:process(A, B, opcode, tempA_sig, tempB_sig)

	begin
		-- cases for each opcode	
		case opcode is
		
			when "000" => --unsigned add
				result_sig <= tempA_sig + tempB_sig;
		
			when "001" => --signed add
				result_sig <= tempA_sig + tempB_sig;
			
			when "010" => --unsigned sub 
				result_sig <= tempA_sig + (not(tempB_sig)) +1;
		
			when "011" => --signed sub
				result_sig <= tempA_sig + (not(tempB_sig) + 1);
				
			when "100" => --bit-wise AND
				result_sig <= ('0' & A) and ('0' & B);
				
			when "101" => --bit-wise OR
				result_sig <= ('0' & A) or ('0' & B);

			when "110" => --bit-wise XOR
				result_sig <= ('0' & A) xor ('0' & B);
				
			when "111" => --divide A by 2
				result_sig <= "00" & A(NUMBITS-1 downto 1);
			
			when others =>	
				result_sig <= (others => '0');
		end case;
		
	end process;
		

overflow_pr:process(A, B, opcode, result_sig)

	begin
		case opcode is
			when "000" => --unsigned add opcode
				if ( result_sig(NUMBITS) = '1' ) then
					overflow_sig <= '1';
				else
					overflow_sig <= '0';
				end if;
			
			when "001" => --signed add opcode
	
				if( (A(NUMBITS-1) = '0' and B(NUMBITS-1) = '0' and result_sig(NUMBITS-1) ='1' )
					or (A(NUMBITS-1) = '1' and B(NUMBITS-1) = '1' and result_sig(NUMBITS-1) = '0' ) )then
					overflow_sig <= '1';	
				else
					overflow_sig <= '0';
				end if;
			
			when "010" => --unsigned sub opcode
				if ( A < B ) then
					overflow_sig <= '1';
				else
					overflow_sig <= '0';
				end if;
				
			when "011" => --signed sub opcode
				if ( (A(NUMBITS-1) = '0' and B(NUMBITS-1) = '1' and result_sig(NUMBITS-1) = '1' )
					or ( A(NUMBITS-1) = '1' and B(NUMBITS-1) ='0' and result_sig(NUMBITS-1) = '0' ) ) then
					overflow_sig <= '1';
				else
					overflow_sig <= '0';
				end if;
			when others =>
				overflow_sig <= '0';
		end case;

	end process;
	
zero_pr:process(result_sig)

	begin
		if ( result_sig (NUMBITS downto 0 ) = ('0' & ZEROS) ) then
			zero_sig <= '1';
		else 
			zero_sig <= '0';
		end if;

	end process;

carryout_pr:process(opcode, result_sig)
	begin
		if ( opcode = "010" or opcode = "011" ) then
			carry_sig <= not(result_sig(NUMBITS));
		else
			carry_sig <= result_sig(NUMBITS);
		end if;
	end process;
	
result <= result_sig(NUMBITS-1 downto 0);
carryout <= carry_sig;
zero <= zero_sig;
overflow <= overflow_sig;
	
end Behavioral;

