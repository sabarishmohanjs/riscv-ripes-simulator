# 24_factorial

### High-Level Language (HLL) Code
```
int factorial(int n) {
if (n <= 1)
return 1;

else
return (n * factorial(n − 1));
}
```
---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. The function `factorial` computes `n!` recursively using the standard definition:  
   - If `n <= 1`, return 1 (base case).  
   - Otherwise, return `n * factorial(n - 1)`.
2. Each recursive call allocates stack space to save the return address (`ra`) and the current argument `n` before calling itself with `n - 1`.
3. When the base case is reached (`n <= 1`), the function returns 1 without further recursion.
4. As the recursive calls return, each instance multiplies the returned factorial value by its saved original `n` to compute the product.
5. After computation, the function restores the saved `ra` and stack pointer before returning to the caller.

  This code demonstrates a classic recursive factorial implementation, managing stack frames to preserve return addresses and parameters, enabling nested calls and proper result accumulation on return. 

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
