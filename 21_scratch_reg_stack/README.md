# 21_scratch_reg_stack

### High-Level Language (HLL) Code

Same code as the 19_func_call_return

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. The `main` function initializes `y` (`s0`) to 0 and prepares the function arguments `2, 3, 4, 5` in registers `a0` to `a3`.  
2. `jal ra, diffofsums` calls the `diffofsums` function, saving the return address in `ra`.  
3. Inside `diffofsums`, the stack pointer `sp` is decremented by 4 bytes to allocate space for saving `s3`.  
4. `s3` is saved on the stack (`sw s3, 0(sp)`) to preserve its original value since it's a callee-saved register.  
5. The function computes `(f + g) - (h + i)` using temporary registers `t0` and `t1`, stores the result in `s3`, then moves it back to `a0` for the return value.  
6. Before returning, `s3` is restored from the stack (`lw s3, 0(sp)`), the stack space is deallocated (`addi sp, sp, 4`), and `jr ra` returns to the caller. The result is then saved in `y` (`s0`) in `main`.
 
  This code demonstrates a function call with proper stack handling where only the callee-saved register `s3` is preserved, and 
  temporary registers are used without save/restore, following RISC-V calling conventions.  

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
