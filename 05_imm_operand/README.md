# 05_imm_operand

### High-Level Language (HLL) Code

a = a + 4; 
b = a − 12;


---------------------------------------------------------------

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---------------------------------------------------------------

### Explanation of the ALP Code

### Explanation of the ALP Code

This program performs two immediate arithmetic operations on registers.

1. `addi s0 s0 4`: This instruction adds the immediate value `4` to the current value of register `s0` and stores the new result back into `s0`.
2.  `addi s1 s0 -12`: This instruction takes the updated value of `s0`, adds the immediate value `-12` (which is a subtraction of 12), and stores the final result in register `s1`.

------------------------------------------------------

### Program Result

The result of the program can be seen in the uploaded screenshot.
