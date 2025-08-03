# 16_for

### High-Level Language (HLL) Code

// add the numbers from 0 to 9 
int sum = 0;
int i;
for (i = 0; i < 10; i = i + 1) {
sum = sum + i;
}

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. `addi s0, zero, 0` initializes the loop counter `i` in register `s0` to 0.  
2. `addi t0, zero, 10` loads the constant value 10 into register `t0`, which is the loop limit.  
3. `addi s1, zero, 0` initializes `sum` in register `s1` to 0.  
4. The label `for:` marks the start of the loop.  
5. `bge s0, t0, exit` checks if `i` (`s0`) is greater than or equal to 10; if yes, the loop exits.  
6. Inside the loop:  
   - `addi s1, s1, 1` increments `sum` by i 
   - `addi s0, s0, 1` increments `i` by 1.  
   - `j for` jumps back to the start of the loop.

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
