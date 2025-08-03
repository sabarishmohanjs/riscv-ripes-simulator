.text
.global _start
_start:
    addi t3, zero, 42     # t3 = 42
    sw t3, 20(zero)       # store t3 (42) into memory address 20
