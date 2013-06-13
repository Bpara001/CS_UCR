
library ieee;
use ieee.std_logic_1164.all;

entity myFF is
    port(C, D, we, rst : in std_logic;
         Q    : out std_logic);
end myFF;

architecture archi of myFF is
begin
    process (C)
    begin
        if (C'event and C='1') then
				if rst='1' then   
					Q <= '0';
				elsif we ='1' then
					Q <= D;
				end if;
        end if;
    end process;
end archi;
				