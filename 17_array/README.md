# 17_array

### High-Level Language (HLL) Code

word[0] = word[0] * 2;
word[1] = word[1] * 2;
---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. The `.data` section declares an array `word` initialized with two 32-bit values: `1` and `2`.  
2. `_main:` marks the program entry point in the `.text` section.  
3. `la t0, word` loads the base address of the array `word` into register `t0`.  
4. `lw s0, 0(t0)` loads the first element (`1`) from the array into `s0`.  
5. `slli s0, s0, 1` multiplies this value by 2 (left shift by 1), resulting in `2`, and `sw s0, 0(t0)` stores it back to the first element.  
6. Similarly, `lw s0, 4(t0)` loads the second element (`2`), doubles it to `4` with `slli`, and stores it back using `sw s0, 4(t0)`.

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
