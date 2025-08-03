# 23_non_leaf_func

### High-Level Language (HLL) Code
```
int f1(int a, int b) {
int i, x;
x = (a + b)*(a − b);
for (i = 0; i < a; i++)
x = x + f2(b + i);
return x;
}

int f2(int p) {
int r;
r = p + 5; return r + p;
}
```
---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. `main` sets `a = 2`, `b = 1`, calls `f1(a, b)`, and stores the result in `s2`.  
2. `f1` computes `(a + b) * (a - b)` and stores in `x` (`s1`), saving necessary registers on the stack.  
3. It runs a loop from `i = 0` to `i < a`, calling `f2(b + i)` each time and adding the result to `x`.  
4. `f2` computes `p + 5 + p` and returns the value.  
5. After the loop, `f1` returns the final `x` to `main`, restoring registers and stack.

The code calculates `(a+b)*(a-b)` plus the sum of `f2(b+i)` for `i` in `[0, a)`, with proper stack and register handling to follow calling conventions. 
---

### Program Result

The result of the program can be seen in the uploaded screenshot.
