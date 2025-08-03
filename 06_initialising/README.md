# 06_intialising

### High-Level Language (HLL) Code

i = 0; 
x = 2032;
y = −78;


---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code


1. `addi` is an instruction that adds an immediate value to a register value.  
2. Each instruction adds a constant value to the `zero` register, which always holds 0.  
3. `addi s4 zero 0` sets register `s4` to 0.  
4. `addi s5 zero 2032` sets register `s5` to 2032.  
5. `addi s6 zero -78` sets register `s6` to -78.



---

### Program Result

The result of the program can be seen in the uploaded screenshot.
