#// determines the power // of x such that 2 x = 128 
#int pow = 1;
#int x = 0;
#do {
#pow = pow * 2; x = x + 1;
#} while (pow != 128);

addi s0,zero,1
addi s1,zero,0
addi t0,zero,128
while:
    slli s0,s0,1
    addi s1,s1,1
    bne s0,t0,while
    j exit
exit:j exit