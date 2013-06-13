----------------------------------------------------------------------------------
--Names: James Fang, Chris Wong
--Login: jfang003, wongc
--Email: jfang003@ucr.edu, cwong030@ucr.edu
--Lab Section: 0##
--Assignment: Lab #2
--I acknowledge all content is original.
----------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY lab2_tb IS
END lab2_tb;
 
ARCHITECTURE behavior OF lab2_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT lab2_vhdl
    PORT(
         floating : IN  std_logic_vector(31 downto 0);
         fixed : OUT  std_logic_vector(31 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal floating : std_logic_vector(31 downto 0) := (others => '0');

 	--Outputs
   signal fixed : std_logic_vector(31 downto 0);
   -- No clocks detected in port list. Replace <clock> below with 
   -- appropriate port name 
 
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: lab2_vhdl PORT MAP (
          floating => floating,
          fixed => fixed
        );

   -- Clock process definitions

   -- Stimulus process
   stim_proc: process
   begin		
      wait for 20ns;
		
		---------------------------------------------------------
		--Test1
		---------------------------------------------------------
		report "Test case 1";
		floating <=  "01000001000001000000000000000000";
		wait for 20ns;
		assert fixed="00000000000001000010000000000000" 
		report "Test_1: fixed" severity Warning;
		
		---------------------------------------------------------
		--Test2
		---------------------------------------------------------
		report "Test case 2";
		floating <=  "01000100100000000001000000000000";
		wait for 20ns;
		assert fixed="00000010000000000100000000000000" 
		report "Test_2: fixed" severity Warning; 
		
		---------------------------------------------------------
		--Test3
		---------------------------------------------------------
		report "Test case 3";
		floating <=  "01001000100000000000000000010000";
		wait for 20ns;
		assert fixed="00000000000000000100000000000000" 
		report "Test_3: fixed" severity Warning;
		
		---------------------------------------------------------
		--Test4
		---------------------------------------------------------
		report "Test case 4";
		floating <=  "01001010100000000000000000000001";
		wait for 20ns;
		assert fixed="00000000000000000100000000000000" 
		report "Test_4: fixed" severity Warning;
		
		---------------------------------------------------------
		--Test5
		---------------------------------------------------------
		report "Test case 5";
		floating <=  "00111010100000000000000000000000";
		wait for 20ns;
		assert fixed="00000000000000000000000000100000" 
		report "Test_5: fixed" severity Warning;
		
		---------------------------------------------------------
		--Test6
		---------------------------------------------------------
		report "Test case 6";
		floating <= "00110111100000000000000000000000";
		wait for 20ns;
		assert fixed="00000000000000000000000000000000" 
		report "Test_6: fixed" severity Warning;
		
		
		---------------------------------------------------------
		--Test7
		---------------------------------------------------------
		report "Test case 7";
		floating <=  "11000001000001000000000000000000";
		wait for 20ns;
		assert fixed="11111111111110111110000000000000" 
		report "Test_7: fixed" severity Warning;
						 
      wait;
   end process;

END;
