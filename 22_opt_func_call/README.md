# 22_opt_func_call

### High-Level Language (HLL) Code

Same code as 19_func_call_return

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. The `main` function initializes `y` (`s0`) to 0 and loads arguments `2, 3, 4, 5` into `a0` to `a3`.  
2. `jal ra, diffofsums` calls the `diffofsums` function, saving the return address in `ra`.  
3. Inside `diffofsums`, it calculates `(f + g) - (h + i)` by:  
   - Adding `a0` and `a1` into `t0`  
   - Adding `a2` and `a3` into `t1`  
   - Subtracting `t1` from `t0` and storing the result in `a0` (the return register).  
4. `jr ra` returns control to `main` with the result in `a0`.  
5. Back in `main`, the result is moved from `a0` into `s0` (`y`), then the program jumps to an infinite loop at `exit`.

This code demonstrates a simple function call that computes `(f + g) - (h + i)` without using stack or register saving because no callee-saved registers are modified.
The result is returned in `a0` and stored in `y` in `main`.

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
