.data
word: .word 1,2 #initialising the array
.text
.global main
main:
    la t0,word
    lw s0,0(t0)
    slli s0,s0,1 #mul by two
    sw s0,0(t0)
    
    lw s0,4(t0)
    slli s0,s0,1
    sw s0,4(t0)
    
exit: j exit	