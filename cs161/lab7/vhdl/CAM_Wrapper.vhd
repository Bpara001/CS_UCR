
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;



entity CAM_Wrapper is
	Generic (CAM_WIDTH : integer := 8 ;
				CAM_DEPTH : integer := 8 ) ;
    Port ( clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
           we_decoded_row_address : in  STD_LOGIC_VECTOR (CAM_DEPTH-1 downto 0);
           search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
			  decoder_sig : in STD_LOGIC;
			  control_update_sig : in STD_LOGIC;
           decoded_match_address : out  STD_LOGIC_VECTOR (CAM_DEPTH-1 downto 0));
end CAM_Wrapper;


architecture Behavioral of CAM_Wrapper is

component CAM_Array is
	Generic (CAM_WIDTH : integer := 8 ;
				CAM_DEPTH : integer := 4 ) ;
	Port (  clk : in  STD_LOGIC;
           rst : in  STD_LOGIC;
			  we_decoded_row_address : in STD_LOGIC_VECTOR(CAM_DEPTH-1 downto 0) ;
			  search_word : in  STD_LOGIC_VECTOR (CAM_WIDTH-1 downto 0);
			  decoder_sig : in STD_LOGIC;
			  control_update_sig : in STD_LOGIC;
			  
           decoded_match_address : out  STD_LOGIC_VECTOR (CAM_DEPTH-1 downto 0));
end  component ;


signal rst_buffered : STD_LOGIC ;
signal we_decoded_row_address_buffered : STD_LOGIC_VECTOR(CAM_DEPTH-1 downto 0) ;
signal search_word_buffered : STD_LOGIC_VECTOR(CAM_WIDTH-1 downto 0) ;
signal decoded_match_address_sig, decoded_match_address_buffered : STD_LOGIC_VECTOR(CAM_DEPTH-1 downto 0);
constant zeroes : STD_LOGIC_VECTOR(CAM_Depth-2 downto 0) :=(others => '0');
signal decoder_sig_buffered : STD_LOGIC;
signal control_update_sig_buffered : STD_LOGIC;
signal circular_queue : STD_LOGIC_VECTOR(CAM_DEPTH-1 downto 0);
constant zeroes1 : STD_LOGIC_VECTOR(CAM_Depth-1 downto 0) :=(others => '0');


begin

circular_queue(CAM_DEPTH-1) <= '1';
circular_queue(CAM_DEPTH-2 downto 0) <= zeroes;

decoded_match_address <= decoded_match_address_buffered ;

process(clk, rst, we_decoded_row_address, search_word, decoded_match_address_sig,decoder_sig,control_update_sig,circular_queue)
begin 

if(clk'event and clk='1')then
	rst_buffered <= rst ;
	
	if(decoder_sig = '1') then
	
		if(control_update_sig = '1') then --when one must update -> set write enable to appropiate values
			we_decoded_row_address_buffered <= we_decoded_row_address ;
			search_word_buffered <= search_word;
			decoded_match_address_buffered <= decoded_match_address_sig ;
			--circular_queue <= circular_queue(CAM_DEPTH-1 downto 1) & circular_queue(0);
		
		end if;
		
	end if;
	
end if ;

end process ;


CAM_Array_pmX: CAM_Array generic map ( 
   CAM_WIDTH => CAM_WIDTH,
   CAM_DEPTH => CAM_DEPTH 
)
port map (
   clk => clk ,
   rst => rst_buffered ,
   we_decoded_row_address => we_decoded_row_address_buffered,
   search_word => search_word_buffered ,
   decoded_match_address => decoded_match_address_sig ,
	decoder_sig => decoder_sig_buffered ,
	control_update_sig => control_update_sig_buffered
);

end Behavioral;

