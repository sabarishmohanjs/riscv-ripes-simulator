# 15_do_while

### High-Level Language (HLL) Code

// determines the power // of x such that 2 x = 128 int pow = 1;
int x = 0;
do {
pow = pow * 2; x = x + 1;
} while (pow != 128)


---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. `addi s0, zero, 1` initializes `pow` (in `s0`) to 1.  
2. `addi s1, zero, 0` initializes `x` (in `s1`) to 0.  
3. `addi t0, zero, 128` stores the constant 128 in `t0` for comparison.  
4. The loop starts at label `while:`.  
5. Inside the loop, `slli s0, s0, 1` multiplies `pow` by 2 (left shifts `s0` by 1), and `addi s1, s1, 1` increments `x` by 1.  
6. `bne s0, t0, while` repeats the loop while `pow` (`s0`) is not equal to 128, and `j exit` ends the loop when `pow` equals 128.
---

### Program Result

The result of the program can be seen in the uploaded screenshot.
