#int f1(int a, int b) {
#int i, x;
#x = (a + b)*(a − b);
#for (i = 0; i < a; i++)
#x = x + f2(b + i);
#return x;
#}
#int f2(int p) {
#int r;
#r = p + 5; return r + p;
#}
.text
.globl main

main:
    addi a0, zero, 2     # a = 2
    addi a1, zero, 1     # b = 1
    jal ra, f1           # call f1(a, b)
    add s2, a0, zero     # store result in s2 (result = f1(a, b))

halt:                    # infinite loop to simulate halt
    j halt
    
f1:
    #i->s0 x->s1 a->a0 b->a1
    addi sp,sp,-12
    sw ra,8(sp)
    sw s1,4(sp)
    sw s0,0(sp)
    add t0,a0,a1
    sub t1,a0,a1
    mul s1,t0,t1 #(a + b)*(a − b);
    addi s0,zero,0
for:
    bge s0,a0,exit
    addi sp,sp,-8
    sw a0,4(sp)
    sw a1,0(sp) #preserved
    add a0,a1,s0
    jal f2
    add s1,s1,a0
    lw a0,4(sp)   
    lw a1,0(sp)
    addi sp,sp,8
    addi s0,s0,1
    j for
exit:
    add a0,zero,s1
    lw ra,8(sp)
    lw s1,4(sp)
    lw s0,0(sp)
    addi sp,sp,12
    jr ra
   #r->s4 p->a0 
f2:
    addi sp,sp,-4
    sw s4,0(sp)
    addi s4,a0,5
    add a0,s4,a0
    lw s4,0(sp)
    addi sp,sp,4
    jr ra