# 14_while

### High-Level Language (HLL) Code

// determines the power 
// of x such that 2 x = 128
int pow = 1;
int x = 0;
while (pow != 128) {
pow = pow * 2;
x = x + 1;
}

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code
1. `addi s0, zero, 1` initializes `pow` (in `s0`) to 1.  
2. `addi s1, zero, 0` initializes `x` (in `s1`) to 0.  
3. `addi t0, zero, 128` sets a constant 128 in `t0` for comparison.  
4. `while:` is the loop start label.  
5. `beq s0, t0, exit` exits the loop if `pow` (`s0`) equals 128.  
6. Inside the loop, `slli s0, s0, 1` multiplies `pow` by 2 (left shift by 1), and `addi s1, s1, 1` increments `x` by 1; then it jumps back to `while` to repeat.
---

### Program Result

The result of the program can be seen in the uploaded screenshot.
