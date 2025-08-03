# 10_storing_mem

### High-Level Language (HLL) Code

mem[5] = 42;// chosen as an example

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code


1. `_start:` marks the program entry point in the `.text` section.  
2. `addi t3, zero, 42` loads the immediate value `42` into register `t3`.  
3. `sw t3, 20(zero)` stores the 32-bit value from `t3` into memory at address `20`.  
4. The `sw` (store word) instruction writes a full word (4 bytes) from a register into memory using a base register plus offset addressing.  
5. This example shows how to store a register’s value into a specific memory address (here, memory word 5 which is at byte address 20).  


---

### Program Result

The result of the program can be seen in the uploaded screenshot.
