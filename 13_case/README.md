# 13_case

### High-Level Language (HLL) Code

switch (button) {
case 1: amt = 20; break;
case 2: amt = 50; break;
case 3: amt = 100; break;
default: amt = 0;
}
// equivalent function using // if/else statements
if (button = = 1) amt = 20; 
else if (button = = 2) amt = 50;
else if (button = = 3) amt = 100;
else amt = 0;

---

### RISC-V Assembly Language (ALP) Code

The `.s` file in this folder contains the corresponding RISC-V assembly language code.

---

### Explanation of the ALP Code

1. The code simulates a `switch` statement on `s0` (which is set to 2).  
2. It compares `s0` with case values (1, 2, 3) using `bne` and branches to the matching case.  
3. For `case 2` (when `s0` equals 2), it sets `s1` to 50.  
4. Each case ends with a jump to `exit` to prevent fall-through.  
5. The `default` case sets `s1` to 0 if no case matches.  
6. Here, since `s0 = 2`, the code sets `amt = 50` in `s1`.

---

### Program Result

The result of the program can be seen in the uploaded screenshot.
