module regfile64 (
    input  logic        clk,        // Clock
    input  logic        reset,      // Reset signal
    input  logic        we,         // Write Enable
    input  logic [4:0]  rs1,        // Source register 1 index
    input  logic [4:0]  rs2,        // Source register 2 index
    input  logic [4:0]  rd,         // Destination register index
    input  logic [63:0] wd,         // Write Data
    output logic [63:0] rd1,        // Read Data 1
    output logic [63:0] rd2         // Read Data 2
);

    logic [63:0] regs[31:0];



    // Reset and write logic
    always_ff @(posedge clk or posedge reset) begin
        if (reset) begin
            for (int i = 0; i < 32; i++) begin
                regs[i] <= 64'd0;
            end
        end else if (we && rd != 5'd0) begin
            regs[rd] <= wd;
        end
    end

    assign rd1 = regs[rs1];
    assign rd2 = regs[rs2];

endmodule

/*
always_ff @(posedge clk) begin
  if (reset == 1) begin
    rs1 <= 5'd0;
    rs2 <= 5'd0;
    we <= 0;
  end else begin
    rs1 <= 5'd1;
    rs2 <= 5'd1;
    we <= 1;
end
*/


/*
module(
    input clk,
    input reset,
    input count,
    input rd,
    input wrt,
    input [31:0] rgstr1,
    input [31:0] rgstr2,
    output result
);
*/
