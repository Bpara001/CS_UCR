--##############################
--Names: Hans Wun, Chris Wong
--Login: wunh, wongc
--Email: hwun001@ucr.edu, wongc@cs.ucr.edu
--Lab Section: 022
--Assignment: Lab 7
--I acknowledge all content is original.
--##############################
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity my_cache is
end my_cache;

architecture Behavioral of my_cache is

	component Control is 
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

	end component;
	
	component mux is
		port(
			sel : in std_logic_vector( 2 downto 0 );
			input : in std_logic_vector(4 downto 0);
			output : out std_logic
		);
		
	end component;
	
	component decoder is
		port( 
			input : in std_logic_vector(4 downto 0);
			output : out std_logic_vector( 31 downto 0)
		);
		
	end component;
	
	component CAM_Array is
			Generic (CAM_WIDTH : integer := 8 ;
				CAM_DEPTH : integer := 4 ) ;
			Port (  clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
			  we_decoded_row_address : in STD_LOGIC_VECTOR(CAM_DEPTH-1 downto 0) ;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           decoded_match_address : out  STD_LOGIC_VECTOR (CAM_DEPTH-1 downto 0);
			  decoder_sig : in STD_LOGIC;
			  control_update_sig : in STD_LOGIC
			  
			  
			  );
			  
	end component;
	
	component CAM_Row is
		Generic (CAM_WIDTH : integer := 8) ;
		Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           row_match : out  STD_LOGIC);

	end component;
	
	component CAM_Cell is
	 Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
	end component;
	

	begin


end Behavioral;

library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;


entity Control_unit is
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

end Control_unit;

architecture bhv of Control_unit is

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


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;



entity CAM_Array is
	Generic (CAM_WIDTH : integer := 8 ;
				CAM_DEPTH : integer := 4 ) ;
	Port (  clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
			  we_decoded_row_address : in STD_LOGIC_VECTOR(CAM_DEPTH-1 downto 0) ;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           decoded_match_address : out  STD_LOGIC_VECTOR (CAM_DEPTH-1 downto 0);
			  decoder_sig : in STD_LOGIC;
			  control_update_sig : in STD_LOGIC
			  
			  
			  );
			  
end CAM_Array;

architecture Behavioral of CAM_Array is

component CAM_Row is
	Generic (CAM_WIDTH : integer := 8) ;
	Port (  clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           row_match : out  STD_LOGIC);
end component ;


begin

-- Connect the CAM rows here
	gen_sub : for N in 0 to CAM_DEPTH-1 generate
			forward_unit : CAM_ROW
				port map (
			  clk => clk,
           rst => rst,
           we => we_decoded_row_address(N),
           search_word => search_word,
           row_match => decoded_match_address(N)
				);
				
		end generate gen_sub;

end Behavioral;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity CAM_Row is
		Generic (CAM_WIDTH : integer := 8) ;
		Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           row_match : out  STD_LOGIC);
end CAM_Row;

architecture Behavioral of CAM_Row is


component CAM_Cell is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
end component ;

constant num_one : std_logic := '1';
signal row_bits : std_logic_vector( CAM_WIDTH downto 0);

begin

		valid_bit: CAM_Cell
			port map ( 
			  clk => clk,
           rst => rst,
           we => we,
           cell_search_bit => '1',
			  cell_match_bit_in => num_one,
           cell_match_bit_out => row_bits(0)
			);

		
		start : CAM_Cell
			port map ( 
			  clk => clk,
           rst => rst,
           we => we,
           cell_search_bit => search_word(0),
			  cell_match_bit_in => row_bits(0),
           cell_match_bit_out => row_bits(1)
				);

		gen_sub : for N in 2 to CAM_WIDTH generate
			forward_unit : CAM_Cell
				port map (
			  clk => clk,
           rst => rst,
           we => we,
           cell_search_bit => search_word(N-1),
			  cell_match_bit_in => row_bits(N-1),
           cell_match_bit_out => row_bits(N)
					);
		end generate gen_sub;

		row_match <= row_bits(CAM_WIDTH);

end Behavioral;


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity CAM_Cell is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
end CAM_Cell;

architecture Binary_Cell of CAM_Cell is

	COMPONENT myFF 
    port(C, D, we, rst : in std_logic;
         Q    : out std_logic);
	end COMPONENT;
	
	signal Q : std_logic;
begin
	ffd:   myFF port map(
				C => clk,
				D => cell_search_bit,
				we => we,
				rst =>rst,
				Q => Q
				);
	 process (clk)
    begin
        if (clk'event and clk='1') then
				cell_match_bit_out <= cell_match_bit_in and  ( cell_search_bit xnor Q ) ;
        end if;
    end process;

end Binary_Cell ;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity decoder is
	port( 
	input : in std_logic_vector(4 downto 0);
	output : out std_logic_vector( 31 downto 0)
	);
end decoder;

architecture behavior of decoder is
begin
	 with input select output <=
		"00000000000000000000000000000001" when "00000",
		"00000000000000000000000000000010" when "00001",
		"00000000000000000000000000000100" when "00010",
		"00000000000000000000000000001000" when "00011",
		"00000000000000000000000000010000" when "00100",
		"00000000000000000000000000100000" when "00101",
		"00000000000000000000000001000000" when "00110",
		"00000000000000000000000010000000" when "00111",
		"00000000000000000000000100000000" when "01000",
		"00000000000000000000001000000000" when "01001",
		"00000000000000000000010000000000" when "01010",
		"00000000000000000000100000000000" when "01011",
		"00000000000000000001000000000000" when "01100",
		"00000000000000000010000000000000" when "01101",
		"00000000000000000100000000000000" when "01110",
		"00000000000000001000000000000000" when "01111",
		"00000000000000010000000000000000" when "10000",
		"00000000000000100000000000000000" when "10001",
		"00000000000001000000000000000000" when "10010",
		"00000000000010000000000000000000" when "10011",
		"00000000000100000000000000000000" when "10100",
		"00000000001000000000000000000000" when "10101",
		"00000000010000000000000000000000" when "10110",
		"00000000100000000000000000000000" when "10111",
		"00000001000000000000000000000000" when "11000",
		"00000010000000000000000000000000" when "11001",
		"00000100000000000000000000000000" when "11010",
		"00001000000000000000000000000000" when "11011",
		"00010000000000000000000000000000" when "11100",
		"00100000000000000000000000000000" when "11101",
		"01000000000000000000000000000000" when "11110",
		"10000000000000000000000000000000" when others;
end behavior;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity mux is 
	port(
	sel : in std_logic_vector( 2 downto 0 );
	input : in std_logic_vector(4 downto 0);
	output : out std_logic
	);
end mux;

architecture behavior of mux is
begin
	with sel select output <=
		input(0) when "000",
		input(1) when "001",
		input(2) when "010",
		input(3) when "011",
		input(4) when others;
end behavior;


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity CAM_Row is
		Generic (CAM_WIDTH : integer := 8) ;
		Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
           row_match : out  STD_LOGIC);
end CAM_Row;

architecture bhv of CAM_Row is


component CAM_Cell is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
end component ;

constant num_one : std_logic := '1';
signal row_bits : std_logic_vector( CAM_WIDTH downto 0);
for all : CAM_Cell use entity work.CAM_Cell(Ternary_at_Input_Cell); 


begin

		valid_bit: CAM_CELL
			port map ( 
			  clk => clk,
           rst => rst,
           we => we,
           cell_search_bit => '1',
			  cell_match_bit_in => num_one,
           cell_match_bit_out => row_bits(0)
			);

		
		start : CAM_CELL
			port map ( 
			  clk => clk,
           rst => rst,
           we => we,
           cell_search_bit => search_word(0),
			  cell_match_bit_in => row_bits(0),
           cell_match_bit_out => row_bits(1)
				);

		gen_sub : for N in 2 to CAM_WIDTH generate
			forward_unit : CAM_CELL
				port map (
			  clk => clk,
           rst => rst,
           we => we,
           cell_search_bit => search_word(N-1),
			  cell_match_bit_in => row_bits(N-1),
           cell_match_bit_out => row_bits(N)
					);
		end generate gen_sub;

		row_match <= row_bits(CAM_WIDTH);

end bhv;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;


entity CAM_Cell is
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we : in  STD_LOGIC;
           cell_search_bit : in  STD_LOGIC;
			  cell_match_bit_in : in  STD_LOGIC ;
           cell_match_bit_out : out  STD_LOGIC);
end CAM_Cell;

architecture Binary_Cell of CAM_Cell is

	COMPONENT myFF 
    port(C, D, we, rst : in std_logic;
         Q    : out std_logic);
	end COMPONENT;
	
	signal Q : std_logic;
begin
	ffd:   myFF port map(
				C => clk,
				D => cell_search_bit,
				we => we,
				rst =>rst,
				Q => Q
				);
	 process (clk)
    begin
        if (clk'event and clk='1') then
				cell_match_bit_out <= cell_match_bit_in and  ( cell_search_bit xnor Q ) ;
        end if;
    end process;

end Binary_Cell ;



