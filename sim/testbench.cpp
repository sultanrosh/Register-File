#include "Vreg_file.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <iomanip>

vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

void tick(Vreg_file* rf, VerilatedVcdC* tfp) {
    rf->clk = 0;
    rf->eval();
    tfp->dump(main_time++);

    rf->clk = 1;
    rf->eval();
    tfp->dump(main_time++);

    rf->clk = 0;
}

// Utility function to write a value to a register
void write_reg(Vreg_file* rf, VerilatedVcdC* tfp, int rd, uint64_t value) {
    rf->rd = rd;
    rf->wd = value;
    rf->we = 1;
    tick(rf, tfp);
    rf->we = 0;
    tick(rf, tfp);
}

// Utility function to read two registers and print them
void read_regs(Vreg_file* rf, VerilatedVcdC* tfp, int rs1, int rs2) {
    rf->rs1 = rs1;
    rf->rs2 = rs2;
    tick(rf, tfp);
    std::cout << "rd1 (reg[" << rs1 << "]): 0x" << std::hex << rf->rd1 << "\n";
    std::cout << "rd2 (reg[" << rs2 << "]): 0x" << std::hex << rf->rd2 << "\n\n";
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vreg_file* rf = new Vreg_file;

    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    rf->trace(tfp, 99);
    tfp->open("reg_file.vcd");

    // Initial reset
    rf->clk = 0;
    rf->reset = 1;
    rf->we = 0;
    rf->rs1 = 0;
    rf->rs2 = 0;
    rf->rd  = 0;
    rf->wd  = 0;
    tick(rf, tfp);
    rf->reset = 0;

    // Write values to multiple registers
    write_reg(rf, tfp, 1, 0x1111111111111111);
    write_reg(rf, tfp, 2, 0x2222222222222222);
    write_reg(rf, tfp, 3, 0x3333333333333333);
    write_reg(rf, tfp, 4, 0x4444444444444444);
    write_reg(rf, tfp, 5, 0x5555555555555555);
    write_reg(rf, tfp, 6, 0x6666666666666666);
    write_reg(rf, tfp, 7, 0x7777777777777777);

    // Attempt to write to reg[0] (should remain zero)
    write_reg(rf, tfp, 0, 0xFFFFFFFFFFFFFFFF);

    // Read back values and print
    read_regs(rf, tfp, 1, 2);
    read_regs(rf, tfp, 3, 4);
    read_regs(rf, tfp, 5, 6);
    read_regs(rf, tfp, 7, 0);  // include reg[0] to check if it's still zero

    // Add idle cycles to stretch the waveform
    std::cout << "Adding idle cycles to stretch waveform...\n";
    for (int i = 0; i < 20; ++i) {
        tick(rf, tfp);
    }

    tfp->close();
    delete tfp;
    delete rf;
    return 0;
}
