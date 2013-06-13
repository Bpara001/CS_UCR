------------------
-- Design of MIPS Controller
------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use work.MIPS_LIB.all;

entity Control is
  port(
    rst : in std_logic;
    clk : in std_logic;
	 valid_in : std_logic;
	 
    hit : in std_logic;
	 wait_for_valid : out std_logic;
	 update : out std_logic;
	 match : out std_logic
    );

end Control;

architecture bhv of Control is

  type state_type is (S0,Swait,Supdate,Smatch);
  signal state, next_state : state_type;
  
  signal s_wait_for_valid : std_logic;
  signal s_update : std_logic;
  signal s_match : std_logic;
  
-- will be defined in "mips_lib.vhd"
-- constant LW     : std_logic_vector( 5 downto 0 ) := "100011";
-- constant SW     : std_logic_vector( 5 downto 0 ) := "101011";
-- constant RTYPE  : std_logic_vector( 5 downto 0 ) := "000000";
-- constant BEQ    : std_logic_vector( 5 downto 0 ) := "000100";
-- constant JUMP   : std_logic_vector( 5 downto 0 ) := "000010";
-- constant DONE   : std_logic_vector( 5 downto 0 ) := "111111";


begin
	
	wait_for_valid <= s_wait_for_valid;
	update <= s_update;
	match <= s_match;
	
  process (rst, clk)
  begin

    if (clk = '1' and clk'event) then
      state <= next_state;

    end if;

  end process;

  process (clk, rst, valid_in, state)
  begin

    if (rst = '1') then
    	next_state <= S0;
	  
    else
			case state is
			  
			when S0 =>	
				next_state <= Swait;	
				
			
			when Swait =>
				
				if (valid_in = 1) then 
					next_state <= Smatch;	
					
				else
					next_state <= Swait;  
					
				end if;
					
			when Smatch =>
				if(hit = 0) then
					next_state <= Supdate;
				else
					next_state <= Swait;
				end if;
				
			
			when Supdate =>	
				next_state <= Swait;	
			
			end case;
		 
     end if;

end process;	

process (clk, rst, state,s_wait_for_valid,s_match,s_update)
	  begin
	  
	  case S0 is
			  when S0 =>	
					s_hit <= '0';
					s_wait_for_valid <= '0';
					s_match <='0';
					s_update <='0';
				
			when Swait =>
				s_wait_for_valid <= '1';
				s_match <='0';
				s_update <='0';
							
			when Smatch =>
				s_wait_for_valid <= '0';
				s_match <='1';
				s_update <='0';
				
			when Supdate =>	
				s_wait_for_valid <= '0';
				s_match <='0';
				s_update <='1';
							
		when others=>
			s_wait_for_valid <= '0';
			s_match <='0';
			s_update <='0';

		end case;  

  end process;	
  
end bhv;


