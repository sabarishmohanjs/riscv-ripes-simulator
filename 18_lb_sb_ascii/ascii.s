.data
char_array: .byte 97,98,99,100

.text
.global start
start:
    la s0,char_array
    addi s1,zero,0 #i
    addi t0,zero,4 #number of elements
for:
    bge s1,t0,exit #condition    if there exists a word then ,
    #sll s0,s1,2 should be done i*4
    add t2,s0,s1    #base+offset
    lb t3,0(t2)    #loading the byte
    addi t3,t3,-32   #calc
    sb t3,0(t2)    #storing
    addi s1,s1,1    #inc i
    j for
exit:j exit