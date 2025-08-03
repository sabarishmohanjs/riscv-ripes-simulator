# 02_subtraction

### High-Level Language (HLL) Code

a = b − c;


------------------------------------------------------------------------------------

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

------------------------------------------------------------------------------------

### Explanation of the ALP Code
1. `addi s1, zero, 10` and `addi s2, zero, 5` initialize registers `s1` and `s2` with values 10 and 5, representing `b` and `c`.  
2. `sub s0, s1, s2` computes `a = b - c` by subtracting `s2` from `s1` and storing the result in `s0`.
---

### Program Result

The result of the program can be seen in the uploaded screenshot.
