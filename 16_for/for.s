#add the numbers from 0 to 9 int sum = 0;
#int i;s0
#for (i = 0; i < 10; i = i + 1) {
#sum = sum + i;s1
#}

addi s0,zero,0
addi t0,zero,10
addi s1,zero,0
for:
    bge s0,t0,exit
    addi s1,s1,1
    addi s0,s0,1
    j for
exit: j exit