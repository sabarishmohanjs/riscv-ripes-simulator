# 12_if_else

### High-Level Language (HLL) Code

if (apples = = oranges)
f = g + h;
else
apples = oranges − h;


---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. `addi s0, zero, 5` sets `s0` (apples) to 5.  
2. `addi s1, zero, 5` sets `s1` (oranges) to 5.  
3. `addi s2, zero, 20` sets `s2` (g) to 20, and `addi s3, zero, 30` sets `s3` (h) to 30.  
4. `bne s0, s1, l1` branches to label `l1` if `s0` (apples) is not equal to `s1` (oranges). Here, since 5 = 5, the branch is NOT taken.  
5. Because the branch is not taken, `add s4, s2, s3` executes, setting `f = g + h` in `s4` (i.e., 20 + 30 = 50).  
6. `j exit` jumps to label `exit`, skipping the `l1` label code.  
7. `l1: sub s0, s1, s3` (which would execute if apples ≠ oranges) subtracts `h` from `oranges` and stores the result back in `s0` (apples). The program ends at `exit: j exit` (an infinite loop at exit).

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
