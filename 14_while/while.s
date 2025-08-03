#int pow = 1;s0
#int x = 0;s1
#while (pow != 128) {
#pow = pow * 2;
#x = x + 1;
#}

addi s0,zero,1
addi s1,zero,0
addi t0,zero,128
while:
    beq s0,t0,exit
    slli s0,s0,1
    addi s1,s1,1
    j while
exit:j exit