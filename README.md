
# 64-Bit Register File Project

This project implements a fully functional **64-bit register file** using Verilog, and tests it using a Verilator-based C++ testbench. The waveform is analyzed using GTKWave. This document explains every corner of the design and simulation process, along with helpful syntax breakdowns and behavioral insights.

---

## Folder Structure

```
reg_file/
├── Makefile
├── rtl/
│   └── reg_file.v
├── sim/
│   └── testbench.cpp
├── obj_dir/  (generated)
├── reg_file.vcd  (generated)
├── Terminal Results.png
└── GTKWave Result.png
```

---

## Module: `reg_file.v`

### Purpose:
To build a 32-register memory array, where each register holds a 64-bit value and can be read from asynchronously and written to synchronously.

### Syntax and Functional Explanation

```verilog
module reg_file (
    input  logic        clk,         // Global clock
    input  logic        reset,       // Reset line (clears all regs)
    input  logic        we,          // Write enable
    input  logic [4:0]  rs1, rs2, rd,// Register indexes: rs1, rs2 (read); rd (write)
    input  logic [63:0] wd,          // Write data
    output logic [63:0] rd1, rd2     // Read data from rs1 and rs2
);
```

- `logic [4:0]` gives us 32 possible register addresses (2⁵ = 32).
- `logic [63:0]` means each register can hold a full 64-bit value.
- `we`: enables writing on a positive clock edge.

```verilog
logic [63:0] regs[31:0]; // 32 registers, each 64-bit wide
```

The internal memory array.

```verilog
always_ff @(posedge clk or posedge reset)
```
- This is clocked logic using `always_ff`, part of SystemVerilog.
- It resets the register file when `reset` goes high.

```verilog
if (reset) begin
    for (int i = 0; i < 32; i++) begin
        regs[i] <= 64'd0;
    end
```

- For loop clears all registers.
- `64'd0` is a constant 64-bit zero.

```verilog
else if (we && rd != 5'd0)
    regs[rd] <= wd;
```

- Prevents writing to register 0 (hardwired to zero).

```verilog
assign rd1 = regs[rs1];
assign rd2 = regs[rs2];
```

- Asynchronous read ports — values are available instantly without clocking.

---

## C++ Testbench: `testbench.cpp`

### Purpose:
To simulate how the register file behaves when values are written and read.

```cpp
#include "Vreg_file.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
```

- `Vreg_file.h`: auto-generated Verilator model of your Verilog.
- `verilated.h`: core Verilator sim support.
- `verilated_vcd_c.h`: allows dumping signals to `.vcd`.

```cpp
vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }
```
- Verilator requires `sc_time_stamp()` to track simulation time.

```cpp
void tick(Vreg_file* rf, VerilatedVcdC* tfp) {
    rf->clk = 0; rf->eval(); tfp->dump(main_time++);
    rf->clk = 1; rf->eval(); tfp->dump(main_time++);
    rf->clk = 0;
}
```

- Simulates a full clock cycle: low → high → low.
- Dumps waveform data to VCD at each step.

### Writing Registers

```cpp
write_reg(rf, tfp, 1, 0x1111111111111111);
```

Calls:
```cpp
void write_reg(Vreg_file* rf, VerilatedVcdC* tfp, int rd, uint64_t value)
```

- Assigns data to register `rd`.
- Toggles clock and enables write.

### Reading Registers

```cpp
read_regs(rf, tfp, 1, 2);
```

Calls:
```cpp
void read_regs(Vreg_file* rf, VerilatedVcdC* tfp, int rs1, int rs2)
```

- Reads from registers `rs1` and `rs2`.
- Prints `rd1` and `rd2` values.

---

## AHA Moments

1. **Understanding register width vs register count**:
   - “Oh — we have **32 total registers**, but each one is **64 bits wide**!”
   - I realized I was confusing "32 registers" with "32-bit registers".

2. **Synchronous write, asynchronous read**:
   - This was a breakthrough. Reads happen instantly, but writes wait for a clock.

3. **Register 0 immutability**:
   - Even though I tried writing to register 0, the testbench proved it remains zero.

4. **Clock edge timing**:
   - I understood why the `tick()` function has two `eval()` calls and VCD dumps — each represents a clock phase.

5. **Waveform visual feedback**:
   - Watching the waveform change live while writing values to `regs[1–7]` made the architecture feel real.

---

## Terminal Output Explained

![Terminal Output](Terminal%20Results.png)

- `reg[1]` through `reg[7]` are loaded with expected 64-bit values.
- `reg[0]` stays 0 even after attempted write — **perfect**.

---

## GTKWave Output Explained

![GTKWave Output](GTKWave%20Result.png)

### Key Signals:
- `we` pulses high to enable writing.
- `wd` shows different values (e.g., 0x111..., 0x222..., etc.)
- `rd1` and `rd2` reflect the values of `rs1` and `rs2`.
- You can clearly trace **when a register is written**, and **when it's read** later.

### Tip:
- Use zoom to analyze each write and read.
- Idle cycles added at the end let you explore without crowding.

---

## How to Write Testbenches for Future Modules

1. **Include Verilator headers**
   ```cpp
   #include "Vyour_module.h"
   #include "verilated_vcd_c.h"
   ```

2. **Define `sc_time_stamp()`**
   ```cpp
   vluint64_t main_time = 0;
   double sc_time_stamp() { return main_time; }
   ```

3. **Toggle the clock manually**
   ```cpp
   clk = 0; eval(); dump();
   clk = 1; eval(); dump();
   ```

4. **Set inputs → evaluate → read outputs**
   - This is how you simulate input → process → observe.

5. **Add helper functions for reuse**
   - `tick()`, `write()`, `read()` abstract logic and keep your code readable.

---

## Makefile Recap

```makefile
all: build run wave

build:
	verilator --cc rtl/reg_file.v --trace --exe sim/testbench.cpp
	make -C obj_dir -f Vreg_file.mk Vreg_file

run:
	./obj_dir/Vreg_file

wave:
	gtkwave reg_file.vcd

clean:
	rm -rf obj_dir reg_file.vcd
```

Run it with:
```bash
make
```

---

## Final Takeaways

- The register file is a fundamental CPU building block.
- You’ve successfully built a **64-bit datapath**, not just storage.
- You learned **how Verilog and C++ interact through Verilator**.
- You learned how to **analyze waveforms and confirm functionality visually**.

---

## Screenshots

### Terminal Output
_(Insert Screenshot Here)_

### GTKWave
_(Insert Screenshot Here)_

---

## Next Steps

- Build an ALU and hook up `rd1`, `rd2` as inputs
- Write back `alu_result` into `regs[rd]`
- Eventually add: instruction memory, PC, and control unit

---

You're now operating like a real CPU architect.


---

## Deep Dive into Verilog Syntax and Semantics

### 1. `logic [63:0] regs[31:0];`

- This is **SystemVerilog syntax**.
- `logic` replaces the older `reg` keyword and is more versatile.
- `[63:0]` → each element is 64 bits wide (bit 63 is MSB, 0 is LSB).
- `[31:0]` → defines a 32-element array.
- So you have **32 registers**, each storing a **64-bit value**.

### 2. `always_ff @(posedge clk or posedge reset)`

- This is a **clocked (sequential) block**.
- `always_ff` is SystemVerilog's way of enforcing flip-flop behavior.
- `posedge clk` → triggers on rising edge of the clock.
- `posedge reset` → allows asynchronous reset.

### 3. `assign rd1 = regs[rs1];`

- This is a **continuous assignment** using a **multiplexer internally**.
- It means: output `rd1` always reflects whatever `regs[rs1]` contains.
- This is asynchronous — it does not depend on the clock.

---

## Deep Dive into C++ Testbench Syntax

### 1. `#include "Vreg_file.h"`

- This header is **auto-generated by Verilator** from your Verilog module.
- It includes C++ class definitions for simulating your Verilog module.

### 2. `VerilatedVcdC* tfp = new VerilatedVcdC;`

- This creates a VCD trace object for dumping waveform data.
- VCD = **Value Change Dump**, which is viewable in GTKWave.

### 3. `rf->eval();`

- `eval()` computes the current output of the module based on the inputs.
- This is **analogous to Verilog's simulation delta cycle evaluation**.

### 4. `tick()` Function

```cpp
void tick(Vreg_file* rf, VerilatedVcdC* tfp) {
    rf->clk = 0;
    rf->eval(); tfp->dump(main_time++);
    rf->clk = 1;
    rf->eval(); tfp->dump(main_time++);
    rf->clk = 0;
}
```

- Simulates a full **clock cycle**: low → high → low
- `main_time++` advances simulation timestamp for accurate waveform timing

### 5. `write_reg()` and `read_regs()` Helpers

These abstract common operations:
- `write_reg()` sets `rd`, `wd`, and `we` to perform a write
- `read_regs()` sets `rs1` and `rs2` and prints the outputs `rd1` and `rd2`

---

## In-Depth Analysis of GTKWave Screenshot

### ![GTKWave Output](GTKWave%20Result.png)

Let’s walk through what’s happening in the waveform:

1. **Reset pulse**
   - `reset` goes high briefly, clearing all 32 registers.
   - No write occurs here.

2. **Write operations (`we = 1`)**
   - `wd` holds new data like `0x1111...`, `0x2222...`, etc.
   - `rd` is incrementing from 1 to 7.
   - This means we’re writing these values into `regs[1]` through `regs[7]`.

3. **Reg[0] write attempt**
   - `rd = 0`, `wd = 0xFFFFFFFFFFFFFFFF`, `we = 1`
   - But value doesn’t show up in `rd2` later — proof that register 0 is protected.

4. **Read operations**
   - `rs1` and `rs2` toggle to select registers 1–7 and 0.
   - `rd1` and `rd2` output the actual values stored.
   - Timing lines up exactly with what you wrote — confirming correct functionality.

5. **Idle cycles**
   - After all operations, the simulation keeps ticking.
   - You see the clock toggling and `we = 0`, meaning no more writes occur.
   - These cycles give you a clearer picture in GTKWave.

---

## In-Depth Analysis of Terminal Output

### ![Terminal Output](Terminal%20Results.png)

Each line like:

```
rd1 (reg[1]): 0x1111111111111111
rd2 (reg[2]): 0x2222222222222222
```

corresponds to a successful **readback** of what was written earlier.

The final line:
```
rd2 (reg[0]): 0x0
```
Confirms:
- Register 0 is immutable.
- Even after writing `0xFFFFFFFFFFFFFFFF`, it remains `0x0`.

---

## Tips for Writing Future Verilator Testbenches

### Structure
- Place your testbench in `/sim/`
- Keep your Verilog RTL in `/rtl/`
- Use a `Makefile` to compile + run

### Reuseable Tick Function
- Always write a `tick()` function that toggles `clk` and dumps waveform
- Use helper functions for repeated operations (like `write_reg`, `read_regs`)

### Debugging Strategy
- Always check waveform **first**
- Print values to terminal for confirmation
- Use `gtkwave` cursors and zoom features

---

## Scaling Up

Now that you have a register file, the next components to build:

1. **ALU (already done)** → wire `rd1`, `rd2` to ALU inputs
2. **Instruction Memory** → simulates fetching binary instruction codes
3. **Control Unit** → decodes opcode, sets `rs1`, `rs2`, `rd`, `we`, etc.
4. **Program Counter** → tracks which instruction is active

---

## Final Screenshots Section

### Terminal Output (Matches Register Values)
_(Insert Screenshot Here)_

### GTKWave Output (Timing + Signal States)
_(Insert Screenshot Here)_

---

## Summary

- You now know **how to write and simulate a register file from scratch**
- You understand:
  - Verilog memory syntax
  - SystemVerilog timing blocks
  - Verilator integration in C++
  - C++ simulation structure and waveform generation

This README was written to be your **personal CPU simulation guidebook**.



---

## Deep Syntax Breakdown of `testbench.cpp`

This section focuses on **explaining line-by-line C++ syntax**, particularly in the functions used to **write** and **read** from the register file. It also includes the **Verilog equivalent** code to reinforce understanding.

---

### `void read_regs(...)` Function

```cpp
void read_regs(Vreg_file* rf, VerilatedVcdC* tfp, int rs1, int rs2) {
    rf->rs1 = rs1;
    rf->rs2 = rs2;
    tick(rf, tfp);
    std::cout << "rd1 (reg[" << rs1 << "]): 0x" << std::hex << rf->rd1 << "\n";
    std::cout << "rd2 (reg[" << rs2 << "]): 0x" << std::hex << rf->rd2 << "\n\n";
}
```

### What does this do?

- `rf->rs1 = rs1;`  
  This line assigns the C++ integer `rs1` to the **hardware register file signal** `rs1`. It maps directly to the Verilog port.

- `tick(rf, tfp);`  
  This ensures the register file has time to react to the new input and propagates the read values through the circuit.

- `std::cout << ...`  
  This is standard C++ output. It uses `std::hex` to display the values in **hexadecimal** format.

---

### Verilog Equivalent for Reading Registers

```verilog
rs1 = 5'd1;
rs2 = 5'd2;
#10; // wait a few cycles (in testbench)
$display("rd1 = %h, rd2 = %h", rd1, rd2);
```

The C++ `read_regs()` function mimics the same steps: assign, wait (via tick), and print.

---

### Main Testbench Logic

```cpp
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);          // Required for Verilator args

    Vreg_file* rf = new Vreg_file;               // Create simulated hardware

    Verilated::traceEverOn(true);                // Enable waveform tracing
    VerilatedVcdC* tfp = new VerilatedVcdC;
    rf->trace(tfp, 99);                          // Trace depth
    tfp->open("reg_file.vcd");                   // Output VCD file

    write_reg(rf, tfp, 7, 0x7777777777777777);    // Write value to reg[7]
    read_regs(rf, tfp, 1, 2);                     // Read from reg[1] and reg[2]

    tfp->close();                                // Close waveform
}
```

### Explanation:

- `Vreg_file* rf = new Vreg_file;`  
  Instantiates the Verilator model of your Verilog module. Think of this like `reg_file uut(...);` in Verilog.

- `traceEverOn` + `trace(tfp, 99)`  
  Enables and configures waveform output. `99` is the depth of tracing.

- `write_reg(...)` and `read_regs(...)`  
  These are custom test helper functions that perform register interactions.

- `tfp->close();`  
  Finalizes and saves the VCD waveform file for GTKWave.

---

### Verilog Equivalent of Main Test Flow

```verilog
initial begin
    reset = 1;
    #5 reset = 0;

    // Write to register 7
    rd = 5'd7;
    wd = 64'h7777777777777777;
    we = 1;
    #10 we = 0;

    // Read from register 1 and 2
    rs1 = 5'd1;
    rs2 = 5'd2;
    #10;

    $finish;
end
```

Just like the C++ testbench:
- We reset the module
- Perform a write
- Perform a read
- Print or view outputs

---

