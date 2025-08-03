# 11_if_statement

### High-Level Language (HLL) Code

if (apples = = oranges)
f = g + h;
apples = oranges − h;

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code


1. `addi s0, zero, 5` sets `s0` (apples) to 5.  
2. `addi s1, zero, 10` sets `s1` (oranges) to 10.  
3. `addi s2, zero, 20` sets `s2` (g) to 20, and `addi s3, zero, 30` sets `s3` (h) to 30.  
4. `bne s0, s1, l1` branches to label `l1` if `s0` (apples) is not equal to `s1` (oranges); since 5 ≠ 10, the branch is taken, skipping the next instruction.  
5. At label `l1`, `sub s5, s1, s3` computes `oranges - h` and stores the result in `s5`.  
6. This code checks if apples equal oranges. If equal, it sets `f = g + h`; otherwise, it computes `apples = oranges - h`. Here, since apples ≠ oranges, only the subtraction at `l1` executes.


---

### Program Result

The result of the program can be seen in the uploaded screenshot.
