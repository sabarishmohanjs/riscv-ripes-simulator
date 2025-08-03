# 19_func_call_return

### High-Level Language (HLL) Code

# 19_func_call_return

### High-Level Language (HLL) Code

```c
int main() {
    int y;
    // some code here...
    y = diffofsums(2, 3, 4, 5);
    // some more code...
}

int diffofsums(int f, int g, int h, int i) {
    int result;
    result = (f + g) - (h + i);
    return result;
}


-----------------------

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. The `main` function initializes `y` to 0 and prepares arguments `2, 3, 4, 5` in registers `a0` to `a3`.  
2. It calls the function `diffofsums` using `jal ra, diffofsums`.  
3. The `diffofsums` function calculates `(f + g) - (h + i)` using the input arguments.  
4. The result is returned in `a0` and stored back into `y` (`s0`) in `main`.  
5. Finally, the program enters an infinite loop at `exit`.
---

### Program Result

The result of the program can be seen in the uploaded screenshot.
