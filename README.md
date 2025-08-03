# riscv_ripes-simulator 🖥️🔧

This repository contains **RISC-V assembly code simulations** developed and tested using the [Ripes Simulator](https://github.com/mortbopet/Ripes), a visual computer architecture simulator for educational purposes.

---

## 🚀 About RISC-V

RISC-V is an open standard **Reduced Instruction Set Computing (RISC)** instruction set architecture (ISA) that is free and extensible.
It is designed to be simple, modular, and efficient, making it ideal for teaching computer architecture as well as for commercial implementations.

---

## 🛠️ What is Ripes Simulator?

Ripes is a user-friendly graphical simulator that allows users to:

- Visualize RISC-V pipelines  
- Simulate assembly programs step-by-step  
- Inspect registers, memory, and control signals  
- Experiment with computer architecture concepts interactively

You can try the online version of Ripes here:  
https://ripes.me/

---

## 📁 Repository Structure

The repository is organized into 24 folders, each named to indicate the covered topic for easy navigation:
```
riscv-ripes-simulator
├── 01_addition
├── 02_subtraction
├── 03_add_sub
├── 04_hll_to_alp
├── 05_imm_operand
├── 06_initialising
├── 07_32bit_load
├── 08_32bit_neg_load
├── 09_reading_mem
├── 10_storing_mem
├── 11_if_statement
├── 12_if_else
├── 13_case
├── 14_while
├── 15_do_while
├── 16_for
├── 17_array
├── 18_lb_sb_ascii
├── 19_func_call_return
├── 20_reg_on_stack
├── 21_scratch_reg_stack
├── 22_opt_func_call
├── 23_non_leaf_func
├── 24_factorial
├── LICENSE
├── README.md
```


---

## 📚 Topics Covered Examples

- **Register_initialization** 🛠️  
  Instructions like `addi`, `lui`, setting registers with immediate values.

- **Memory_load_store** 💾  
  Loading and storing data with `lw`, `sw`, `lb`, `sb`.

- **Control_flow_branching** 🔀  
  Branch instructions `beq`, `bne`, jump instructions, if-else clauses.

- **Loops_iterations** 🔄  
  Common loops in assembly: `for`, `while`, `do-while`.

- **Function_calls_stack** 📞🗄️  
  Stack frame creation, saving/restoring registers, calling conventions.

- **Arithmetic_logic** ➕➖✖️  
  Arithmetic and logical operations: `add`, `sub`, `mul`, shifts.

- **Character_array_manipulation** 🔤🧮  
  Byte-level manipulations, ASCII case conversions.

- **Recursive_algorithms** ♻️  
  Recursive functions like factorial with stack usage.

... and more.

---

## 📖 How to Use This Repo

- Navigate to folders corresponding to the topic of interest.  
- Inside each folder, find RISC-V assembly code along with markdown explanations.  
- Use the online or desktop Ripes simulator to load and run these codes.  
- Modify and experiment with the code snippets to deepen your understanding.

---



## 🔗 Useful Links

- [Ripes GitHub Repository](https://github.com/mortbopet/Ripes)  
- [Ripes Online Simulator](https://ripesonline.cs.brown.edu/)  
- **Reference Book:** *The RISC-V Reader: An Open Architecture Atlas* by Sarah Harris and David Harris


Happy learning and simulating RISC-V! 🚀
