--Names: Hans Wun, Chris Wong
--Login: wunh, wongc
--Email: hwun001@ucr.edu, wongc@cs.ucr.edu
--Lab Section: 0##
--##############################################################################
library IEEE;
use IEEE.std_logic_1164.all;
use IEEE.std_logic_arith.all;
use work.MIPS_LIB.all;

entity wrapper is
    --port(
	 
	--rst : in std_logic;
	--clk : in std_logic;
   
    	 --used for testing
-- ALU Output
 --  testing_alu_result    : out std_logic_vector(31 downto 0);
-- Memory Data Register
	--testing_mem_data : out std_logic_vector(31 downto 0);
-- Register File Output 1
	--testing_read_data_1  : out std_logic_vector(31 downto 0);
-- Register File Output 2
	--testing_read_data_2  : out std_logic_vector(31 downto 0) 
	
	--);
    
end wrapper ;

architecture Behavioral of wrapper is

COMPONENT Datapath
    PORT(
	 
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
   testing_read_data_2  : out std_logic_vector(31 downto 0) 
	
	);
    END COMPONENT;
	 
COMPONENT Control
    PORT(
	
	rst : in std_logic;
    clk : in std_logic;
    alu_src_A  : out std_logic;
    alu_src_B  : out std_logic_vector( 1 downto 0 );
    alu_op     : out std_logic_vector( 1 downto 0 );
    reg_write  : out std_logic;
    reg_dst    : out std_logic;
    pc_source  : out std_logic_vector( 1 downto 0 );
	 pc_write_cond: out std_logic;
    pc_write    : out std_logic;
    i_or_d     : out std_logic;
    mem_read   : out std_logic;
    mem_write  : out std_logic_vector(0 downto 0);
    mem_to_reg : out std_logic;
    IR_write   : out std_logic;
    ins_31_26 : in std_logic_vector( 5 downto 0 );
    alu_zero  : in std_logic

    );
    END COMPONENT;
	 
COMPONENT ALUControl
	 PORT(
		alu_op : in std_logic_vector ( 1 downto 0);
		ins_5_0   	: in std_logic_vector( 5 downto 0 );
      alu_control : out std_logic_vector( 2 downto 0 )
		);
		
	END COMPONENT;

signal rst : std_logic;
signal clk : std_logic;
signal alu_src_A  : std_logic;
signal alu_src_B  : std_logic_vector( 1 downto 0 );
signal alu_op     : std_logic_vector( 1 downto 0 );
signal alu_control : std_logic_vector( 2 downto 0);
signal reg_write  : std_logic;
signal reg_dst    : std_logic;
signal pc_source  : std_logic_vector( 1 downto 0 );
signal pc_write_cond: std_logic;
signal pc_write    : std_logic;
signal i_or_d     : std_logic;
signal mem_read   : std_logic;
signal mem_write  : std_logic_vector(0 downto 0);
signal mem_to_reg : std_logic;
signal IR_write   : std_logic;
signal ins_31_26 : std_logic_vector( 5 downto 0 );
signal alu_zero  : std_logic;

signal ins_5_0   : std_logic_vector( 5 downto 0 );
signal testing_alu_result    :  std_logic_vector(31 downto 0);
signal testing_mem_data :  std_logic_vector(31 downto 0);
signal testing_read_data_1  :  std_logic_vector(31 downto 0);
signal testing_read_data_2  : std_logic_vector(31 downto 0);

begin


	uut: Datapath PORT MAP(
		rst => rst,
		clk => clk,
		alu_src_A => alu_src_A,
		alu_src_B => alu_src_B,
		alu_control => alu_control,
		reg_write => reg_write,
		reg_dst => reg_dst,
		pc_source => pc_source,
		pc_write => pc_write,
		i_or_d => i_or_d,
		mem_read => mem_read,
		mem_write => mem_write,
		mem_to_reg  => mem_to_reg,
		IR_write => IR_write,
		ins_31_26 => ins_31_26,
		ins_5_0 => ins_5_0,
		alu_zero => alu_zero,
		
		testing_alu_result  => testing_alu_result,
		testing_mem_data => testing_mem_data,
		testing_read_data_1 => testing_read_data_1,
		testing_read_data_2  => testing_read_data_2 
	);
	
	uut2:Control PORT MAP(
		 rst => rst,
		 clk => clk,
		 alu_src_A  => alu_src_A,
		 alu_src_B  => alu_src_B,
		 alu_op     => alu_op,
		 reg_write  =>  reg_write,
		 reg_dst    => reg_dst,
		 pc_source  => pc_source,
		 pc_write_cond => pc_write_cond,
		 pc_write => pc_write,
		 i_or_d  => i_or_d,
		 mem_read => mem_read,
		 mem_write => mem_write,
		 mem_to_reg => mem_to_reg,
		 IR_write => IR_write,
		 ins_31_26 => ins_31_26,
		 alu_zero  => alu_zero
	
		);
	
	uut3:ALUControl PORT MAP(
		 alu_op => alu_op,
		 ins_5_0 => ins_5_0,
		 alu_control => alu_control
		 );

	rst <= '0';

 stim_proc: process
   begin
	
	clk <= '1';
	wait for 5ns;
	clk <= '0';
	wait for 5ns;
	
	end process;
	
	
end Behavioral ;
