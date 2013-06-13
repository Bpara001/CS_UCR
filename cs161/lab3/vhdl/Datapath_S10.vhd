-- Datapath
--
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use work.MIPS_LIB.all;

entity Datapath is
    port(
	 
	rst : in std_logic;
	clk : in std_logic;
        --control signals
	alu_src_A : in std_logic;
	alu_src_B : in std_logic_vector( 1 downto 0 );
        -- output from the ALU control 
	alu_control : in std_logic_vector( 2 downto 0 );
	reg_write : in std_logic;
	reg_dst : in std_logic;
	pc_source : in std_logic_vector( 1 downto 0 );
        -- output from the or gate, combining PCWriteCond and PCWrite
   pc_write : in std_logic;
	i_or_d : in  std_logic;
	mem_read : in std_logic;
	mem_write : in std_logic_vector(0 downto 0);
	mem_to_reg : in std_logic;
	IR_write : in  std_logic;
        
        -- output to controller
	ins_31_26 : out std_logic_vector( 5 downto 0 );
        -- output to ALU control
   ins_5_0   : out std_logic_vector( 5 downto 0 );
        -- output to PC write logic
   alu_zero   : out std_logic;

        -- used for testing
   testing_alu_result    : out std_logic_vector(31 downto 0);
   testing_mem_data : out std_logic_vector(31 downto 0);
   testing_read_data_1  : out std_logic_vector(31 downto 0);
   testing_read_data_2  : out std_logic_vector(31 downto 0) );
    
end Datapath;

-- purpose: connect all the components
architecture bhv of Datapath is

component Generic_Register
generic ( NUMBITS : integer := 32) ;
  port(
      rst   : in std_logic;
      clk   : in std_logic;
      load : in std_logic;
      input : in std_logic_vector (31 downto 0);
      output: out std_logic_vector (31 downto 0)
      );
end component;

  
component Mux_32_2_1
    port(
	sel 	: in std_logic;
	input_a	: in std_logic_vector(31 downto 0);
	input_b	: in std_logic_vector(31 downto 0);
	output	: out std_logic_vector(31 downto 0)
	);
end component;

component Mux_5_2_1
    port(
	sel 	: in std_logic;
	input_a	: in std_logic_vector(4 downto 0);
	input_b	: in std_logic_vector(4 downto 0);
	output	: out std_logic_vector(4 downto 0)
	);
end component;

component Mux_32_4_1
    port(
	sel 	: in std_logic_vector(1 downto 0);
	input_a	: in std_logic_vector(31 downto 0);
	input_b	: in std_logic_vector(31 downto 0);
   input_c	: in std_logic_vector(31 downto 0);
   input_d	: in std_logic_vector(31 downto 0);
	output	: out std_logic_vector(31 downto 0)
	);
end component;

component Mux_32_3_1
    port(
	sel 	: in std_logic_vector(1 downto 0);
	input_a	: in std_logic_vector(31 downto 0);
	input_b	: in std_logic_vector(31 downto 0);
	input_c	: in std_logic_vector(31 downto 0);
	output	: out std_logic_vector(31 downto 0)
	);
end component;

component my_MEM_256x32
    port( 
	clka       	: in  std_logic;
	--ena 			: IN STD_LOGIC;
	dina       	: in  std_logic_vector (31 downto 0);
	addra    	: in  std_logic_vector (7 downto 0);
	wea        	: in  std_logic_vector(0 downto 0);
	douta   	: out std_logic_vector (31 downto 0)
	);
end component;

component Reg_File
    port ( 
	rst        : in std_logic;
	clk        : in std_logic;
	reg_write  : std_logic;
	read_reg_1  : in std_logic_vector(4 downto 0);
	read_reg_2  : in std_logic_vector(4 downto 0);
	write_reg  : in std_logic_vector(4 downto 0);
	write_data : in std_logic_vector(31 downto 0);
	read_data_1 : out std_logic_vector(31 downto 0);
	read_data_2 : out std_logic_vector(31 downto 0)
	);		
end component;

component SignExt_16_32
    port(
	input	: in std_logic_vector(15 downto 0);
	output	: out std_logic_vector(31 downto 0)
	);
end component;

component ALU
    port(
	input_a    : in std_logic_vector( 31 downto 0);
	input_b    : in std_logic_vector( 31 downto 0 );
	operation  : in std_logic_vector( 2 downto 0 );	
	zero       : out std_logic;
	result     : out std_logic_vector( 31 downto 0 )
	);
end component;


-- memory address, connect to output of MUX
signal address   : std_logic_vector(31 downto 0);
-- data to write to memory, connect to output of B register
signal mem_write_data : std_logic_vector(31 downto 0);
-- data read from Memory, connect to input of IR and MDR
signal mem_data   : std_logic_vector(31 downto 0);

-- value going into and coming out of PC register
signal new_pc           : std_logic_vector(31 downto 0) := "00000000000000000000000000000000";
signal pc               : std_logic_vector(31 downto 0);
signal pc_crap 			: std_logic_vector (7 downto 0);
-- output from IR
signal instr            : std_logic_vector(31 downto 0);
signal instr_25_0         : std_logic_vector(25 downto 0);
signal instr_31_26        : std_logic_vector(5 downto 0);
signal instr_25_21        : std_logic_vector(4 downto 0);
signal instr_20_16        : std_logic_vector(4 downto 0);
signal instr_15_11        : std_logic_vector(4 downto 0);
signal instr_5_0          : std_logic_vector(5 downto 0);
signal instr_15_0         : std_logic_vector(15 downto 0);

-- output from Memory Data Register
signal MDR_out            : std_logic_vector(31 downto 0);

-- inputs to register file
signal write_reg           : std_logic_vector( 4 downto 0);
signal RF_write_data          : std_logic_vector(31 downto 0);

signal mem_write_s : std_logic_vector( 0 downto 0);

-- output from register file
signal read_data_1          : std_logic_vector(31 downto 0);
signal read_data_2          : std_logic_vector(31 downto 0);

-- output from A and B register
signal reg_A_out            : std_logic_vector(31 downto 0);
signal reg_B_out            : std_logic_vector(31 downto 0);

-- constant 4, used as input to mux
signal four               : std_logic_vector(31 downto 0) := "00000000000000000000000000000100";

-- sign extender output
signal sign_ext_out         : std_logic_vector(31 downto 0);
-- sign extender output shift left twice
signal sign_ext_out_SL2     : std_logic_vector(31 downto 0);

-- ALU inputs and output
signal alu_input_A        : std_logic_vector(31 downto 0);
signal alu_input_B        : std_logic_vector(31 downto 0);
signal alu_result        : std_logic_vector(31 downto 0);

-- output from ALUOut register
signal alu_out           : std_logic_vector(31 downto 0);

-- input to 3 to 1 PC Mux
signal jump_addr         : std_logic_vector(31 downto 0);


begin  -- bhv

  -- PC REGISTER
	U_PCREG: Generic_Register 	
		generic map (NUMBITS => 32)
		port map (
			rst => rst,
         clk => clk,
         load => pc_write,
         input => new_pc,
         output => pc
		);
	
	IR: Generic_Register
		generic map (NUMBITS => 32)
		port map(
			rst => rst,
			clk => clk,
			load => '1',
			input => mem_data,
			output => instr
		);
	
			instr_31_26 <= instr(31 downto 26);
			instr_25_21 <= instr(25 downto 21);
			instr_20_16 <= instr(20 downto 16);
			instr_15_11 <= instr(15 downto 11);
			instr_15_0 <= instr(15 downto 0);
			instr_25_0 <= instr(25 downto 0);
			instr_5_0 <= instr(5 downto 0);
			
		
			ins_5_0 <= instr(5 downto 0);
			ins_31_26 <= instr(31 downto 26);
	
	A_REG : Generic_Register
		generic map (NUMBITS => 32)
		port map(
			rst => rst,
			clk => clk,
			load => '1',
			input => read_data_1,
			output => reg_A_out
		);
	
	B_REG : Generic_Register
		generic map (NUMBITS => 32)
		port map(
			rst => rst,
			clk => clk,
			load => '1',
			input => read_data_2,
			output => reg_B_out
			
		);
	--Memory Data Register
	MDR : Generic_Register
		generic map (NUMBITS => 32)
		port map (
			rst => rst,
			clk => clk,
			load => '1',
			input => mem_data,
			output => MDR_out
			);

	ALUOut : Generic_Register
		generic map (NUMBITS => 32)
		port map(
			rst => rst,
			clk => clk,
			load => '1',
			input => alu_result,
			output => alu_out
			);
	-- MUX taking data from PC
	PCtoMux :  Mux_32_2_1
		port map(
			sel => i_or_d, 
			input_a => pc,
			input_b => alu_out,
			output => address
		);

	--Global memory unit taking from PC->MUX
	mem_write_data <= reg_B_out;
	Memory_Unit :  my_MEM_256x32
		port map( 
			clka => clk,
--			ena => mem_read,
			dina => mem_write_data,
			addra => pc_crap,
			wea => mem_write,
			douta => mem_data
	);
	
	pc_crap <= pc(7 downto 0);
	-- MUX 5bit
	IRtoMUX : Mux_5_2_1
		port map(
			sel => reg_dst,
			input_a	=> instr_20_16,
			input_b	=> instr_15_11,
			output => write_reg
	);
	
	-- MUX 32bit 4 input
    BtoMUX: Mux_32_4_1
		port map(
			sel => alu_src_B,
			input_a	=> reg_B_out,
			input_b	=> four,
			input_c	=> sign_ext_out,
			input_d	=> sign_ext_out_SL2,
			output	=> alu_input_B
	);
	
	sign_ext_out_SL2 <= sign_ext_out(29 downto 0) & "00";
	-- MUX 32bit 3 input
	JumpMux: Mux_32_3_1
	    port map(
			sel => pc_source,
			input_a	=> alu_result,
			input_b	=> alu_out,
			input_c	=> jump_addr,
			output	=> new_pc
	);
	jump_addr <= pc(31 downto 28) & (instr_25_0) & "00";
	
	-- Memory Data Register to MUX
	MDRtoMUX : Mux_32_2_1
		port map(
			sel => mem_to_reg,
			input_a => alu_out,
			input_b => MDR_out,
			output => RF_write_data
	);
	
	AtoMUX : Mux_32_2_1
		port map(
			sel => alu_src_A,
			input_a => pc,
			input_b => reg_A_out,
			output => alu_input_A
			
	);
	-- REG FILE
	RegFile:REG_File
		port map( 
			rst => rst,
			clk => clk,
			reg_write  => reg_write,
			read_reg_1 => instr_25_21,
			read_reg_2 => instr_20_16,
			write_reg  => write_reg,		
			write_data => RF_write_data,		
			read_data_1 => read_data_1,		
			read_data_2 => read_data_2
	);		

	MEM_REGtoSIGN_EXT: SignExt_16_32
		port map(
			input	=> instr_15_0,
			output => sign_ext_out
	);
	
	Muxes_to_Alu: ALU
		port map(
			input_a => alu_input_A,
			input_b => alu_input_B,
			operation => alu_control,
			zero => alu_zero,
			result => alu_result
	);	
	
	testing_alu_result <= alu_result;
	testing_mem_data <= mem_data;
	testing_read_data_1 <= read_data_1;
	testing_read_data_2 <= read_data_2;
	
	


end bhv;
