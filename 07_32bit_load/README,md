# 07_32bit_load

### High-Level Language (HLL) Code

int a = 0xABCDE123;


---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code


1. `lui s0 0xABCDE`  
   Loads the upper 20 bits of register `s0` with the value `0xABCDE0000` (0xABCDE shifted left by 12 bits).
2. `addi s0 s0 0x123`  
   Adds the immediate value `0x123` to the current value in `s0`.
3. Together, these two instructions set `s0` to `0xABCDE123`.
4. This sequence initializes register `s0` with the 32-bit hexadecimal value `0xABCDE123`.
5. Using `lui` plus `addi` is a common way in RISC-V to load a full 32-bit immediate value into a register.


---

### Program Result

The result of the program can be seen in the uploaded screenshot.
