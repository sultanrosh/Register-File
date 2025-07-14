# Top-level module and testbench
TOP       = reg_file
TB_CPP    = sim/testbench.cpp
VERILOG   = rtl/$(TOP).v
OBJ_DIR   = obj_dir
VCD_FILE  = $(TOP).vcd

# Build all (default)
all: build run wave

# Build with Verilator
build:
	verilator --cc $(VERILOG) --trace --exe $(TB_CPP)
	make -C $(OBJ_DIR) -f V$(TOP).mk V$(TOP)

# Run simulation
run:
	./$(OBJ_DIR)/V$(TOP)

# Open GTKWave
wave:
	gtkwave $(VCD_FILE)

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(VCD_FILE)

.PHONY: all build run wave clean
