# 18_lb_sb_ascii

### High-Level Language (HLL) Code

// high-level code
// chararray[10] was declared and initialized earlier
int i;
for (i = 0; i < 10; i = i + 1)
chararray[i] = chararray[i] − 32;

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. The `.data` section defines a byte array `char_array` with ASCII codes for 'a', 'b', 'c', and 'd'.  
2. `la s0, char_array` loads the array’s base address into register `s0`.  
3. `addi s1, zero, 0` initializes the index `i` to 0, and `addi t0, zero, 4` sets the array length.  
4. The loop iterates while `i < 4`, using `bge` to exit when done.  
5. Inside the loop, it calculates the byte address by adding `i` to the base, loads the byte, subtracts 32 to convert lowercase to uppercase, and stores it back.  
6. After processing all bytes, the program loops infinitely at the `exit` label.
7. The code converts characters in the byte array from lowercase to uppercase in place by subtracting 32 from each ASCII value. 
---

### Program Result

The result of the program can be seen in the uploaded screenshot.
