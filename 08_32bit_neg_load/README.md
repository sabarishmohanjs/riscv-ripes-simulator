# [Folder Name]

### High-Level Language (HLL) Code

int a = 0xFEEDA987;


---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code


1. `lui s2, 0xFEEDB` loads `s2` with `0xFEEDB0000`.  
2. The desired upper 20 bits are actually `0xFEEDA`, which is one more than `0xFEEDB`.  
3. To compensate, `addi s2, s2, -1657 (0x987 as a negative immediate)` subtracts 1657 from `s2`.  
4. This works because `addi` sign-extends the 12-bit immediate; negative immediates have all 1’s in upper bits.  
5. Together, these instructions set `s2` to the exact value `0xFEEDA987`.

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
