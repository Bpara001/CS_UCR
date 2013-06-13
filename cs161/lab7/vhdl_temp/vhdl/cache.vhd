----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:44:34 06/01/2012 
-- Design Name: 
-- Module Name:    cache - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity cache is
Port(
	clk : in STD_LOGIC;
	rst : in STD_LOGIC;
	address : in STD_LOGIC_VECTOR(31 downto 0);
	valid_in : in STD_LOGIC;
	ack : out STD_LOGIC;
	hit : out STD_LOGIC;
	valid_out : out STD_LOGIC
);

end cache;

architecture Behavioral of cache is

begin


end Behavioral;

