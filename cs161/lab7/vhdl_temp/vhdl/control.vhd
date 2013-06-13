------------------
-- Design of MIPS Controller
------------------

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;


entity Control is
  port(
    rst : in std_logic;
    clk : in std_logic;
	 valid_in : std_logic;
	 
    hit : in std_logic;
	 wait_for_valid : out std_logic;
	 update : out std_logic;
	 match : out std_logic;
	 ack : out std_logic;
	 valid_out : out std_logic
    );

end Control;

architecture bhv of Control is

  type state_type is (S0,Swait,Supdate,Smatch);
  signal state, next_state : state_type;
  
  signal s_ack : std_logic;  --acknowledge signal
  signal s_wait_for_valid : std_logic; --wait for valid signal
  signal s_update : std_logic; --update signal
  signal s_match : std_logic; --match signal
  signal s_valid_out : std_logic; --valid_out signal
  
begin
	
	wait_for_valid <= s_wait_for_valid;
	update <= s_update;
	match <= s_match;
	
  process (rst, clk)
  begin
	 --on rising edge, transition to next designated state
    if (clk = '1' and clk'event) then
      state <= next_state;

    end if;

  end process;

  process (clk, rst, valid_in, state)
  begin
    --if reset signal is on, set next state to initial
    if (rst = '1') then
    	next_state <= S0;
	  
	 --otherwise
    else
			--if current state is initial
			case (state) is
			  
			   --make next state the wait state
				when S0 =>	
					next_state <= Swait;	
				
				--on wait_for_valid state, if valid_in is 1
				--transition into match state
				when Swait =>
				
					if valid_in = '1' then 
						next_state <= Smatch;	
					
					--otherwise stay and wait for valid input
					else
						next_state <= Swait;  
					
					end if;
				
				--in match state
				when Smatch =>
					--if target is a miss, set next state to update
					--to update cache
					if hit = '0' then
						next_state <= Supdate;
					--otherwise we have a hit, and go back to waiting
					--for valid input
					else
						next_state <= Swait;
					end if;
				
				--in matching state
				when Supdate =>	
					--make next state wait
					next_state <= Swait;	
			end case;
     end if;

end process;	

--transition actions
process (clk, rst, state)
	  begin
	  
	  case state is
			when S0 =>
				s_wait_for_valid <= '0';
				s_match <='0';
				s_update <='0';
				s_valid_out <= '0';
				
			when Swait =>
				s_wait_for_valid <= '1';
				s_ack <= '1';
				s_match <='0';
				s_update <='0';
				s_valid_out <= '0';
				
			when Smatch =>
				s_wait_for_valid <= '0';
				s_ack <= '0';
				s_match <='1';
				s_update <='0';
				s_valid_out <= '1';
				
			when Supdate =>	
				s_wait_for_valid <= '0';
				s_ack <= '0';
				s_match <='0';
				s_update <='1';
				s_valid_out <= '0';
							
		when others=>
			s_wait_for_valid <= '0';
			s_match <='0';
			s_update <='0';
			s_ack <= '0';
			s_valid_out <= '0';

		end case;  

  end process;	
  
end bhv;


