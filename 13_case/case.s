#switch (button) {
#case 1: amt = 20; break;
#}
#case 2: amt = 50; break;
#ase 3: amt = 100; break;
#default: amt = 0;

addi s0,zero,2

#case1:
    addi t0,zero,1
    bne t0,s0,case2
    addi s1,zero,20
    j exit
case2:
    addi t0,zero,2
    bne t0,s0,case3
    addi s1,zero,50
    j exit
case3:
    addi t0,zero,3
    bne t0,s0,default
    addi s1,zero,100
    j exit
default:
    addi s1,zero,0
    j exit
exit: j exit
    