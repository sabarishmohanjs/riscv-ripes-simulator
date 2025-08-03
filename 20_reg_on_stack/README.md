# 20_reg_on_stack

### High-Level Language (HLL) Code

Same code as 19_func_call_on_stack

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code
1. `addi sp, sp, -12`  
   - Allocates 12 bytes (3 words) of stack space by decrementing the stack pointer (`sp`).  
2. `sw s3, 8(sp)`, `sw t0, 4(sp)`, `sw t1, 0(sp)`  
   - Saves registers `s3`, `t0`, and `t1` onto the stack to preserve their original values before modification.
3. After computation, the values in `s3`, `t0`, and `t1` are restored from the stack via `lw` instructions:  
   - `lw s3, 8(sp)`, `lw t0, 4(sp)`, and `lw t1, 0(sp)`.  
4. `addi sp, sp, 12`  
   - Deallocates the 12 bytes of stack space by restoring the stack pointer to its original position.
5. This saving and restoring of registers on the stack preserves caller-saved (`t0`, `t1`) and callee-saved (`s3`) registers across the function call, preventing side effects outside the function.

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
