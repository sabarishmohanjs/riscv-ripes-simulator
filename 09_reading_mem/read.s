.data
a: .word 10
.text
.global _start
_start:
    la s0 a
    lw s0 0(s0)
