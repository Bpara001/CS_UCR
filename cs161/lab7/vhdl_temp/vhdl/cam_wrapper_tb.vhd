--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   20:08:28 05/25/2012
-- Design Name:   
-- Module Name:   D:/Chris_jonatan/cam_wrapper_tb.vhd
-- Project Name:  Chris_jonatan
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: CAM_Wrapper
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY cam_wrapper_tb IS
END cam_wrapper_tb;
 
ARCHITECTURE behavior OF cam_wrapper_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT CAM_Wrapper
    PORT(
         clk : IN  std_logic;
         rst : IN  std_logic;
         we_decoded_row_address : IN  std_logic_vector(7 downto 0);
         search_word : IN  std_logic_vector(7 downto 0);
         dont_care_mask : IN  std_logic_vector(7 downto 0);
         decoded_match_address : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';
   signal we_decoded_row_address : std_logic_vector(7 downto 0) := (others => '0');
   signal search_word : std_logic_vector(7 downto 0) := (others => '0');
   signal dont_care_mask : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal decoded_match_address : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: CAM_Wrapper PORT MAP (
          clk => clk,
          rst => rst,
          we_decoded_row_address => we_decoded_row_address,
          search_word => search_word,
          dont_care_mask => dont_care_mask,
          decoded_match_address => decoded_match_address
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
		rst <= '1';
	
      wait for clk_period*2;
		
		rst <= '0';
		
      wait for clk_period*2;
				
          we_decoded_row_address <= "00000001";
          search_word <= "00000010";
	
      wait for clk_period*2;
				
          we_decoded_row_address <= "00000010";
          search_word <= "00000011";
	
      wait for clk_period*2;
				
          we_decoded_row_address <= "00000100";
          search_word <= "00000110";
	
      wait for clk_period*2;
				
          we_decoded_row_address <= "00001000";
          search_word <= "00001011";
			 
		wait for clk_period*2;
				
          we_decoded_row_address <= "00010000";
          search_word <= "00001111";
			 
		wait for clk_period*2;
				
          we_decoded_row_address <= "00100000";
          search_word <= "00101011";
			 
		wait for clk_period*2;
				
          we_decoded_row_address <= "01000000";
          search_word <= "01001011";
			 
			 
		wait for clk_period*2;
				
          we_decoded_row_address <= "10000000";
          search_word <= "01101011"; 
			 
	 wait for clk_period;
	 
	 
				
          we_decoded_row_address <= "00000000";
          search_word <= "01001011";
			  dont_care_mask <= "00000000";
      

      wait;
   end process;

END;
