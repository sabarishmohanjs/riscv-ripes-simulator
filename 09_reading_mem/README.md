# 09_reading_mem

### High-Level Language (HLL) Code

a = mem[2];

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code


1. The `.data` section defines a word `a` with the value `10`.  
2. `la s0, a` loads the address of `a` into register `s0`.  
3. `lw s0, 0(s0)` loads the 32-bit value stored at address `a` (which is `10`) into register `s0`.  
4. The `lw` (load word) instruction reads 4 bytes (a full word) from memory using the address in `s0` plus an offset (here 0).  
5. This sequence demonstrates how to load a variable's value from memory into a register for use in a program.


---

### Program Result

The result of the program can be seen in the uploaded screenshot.
