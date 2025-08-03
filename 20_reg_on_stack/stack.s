#int main(){
#int y;
#}
#. . .
#y = diffofsums(2, 3, 4, 5);
#. . .
#int diffofsums(int f, int g, int h, int i){
#int result;
#}
#result = (f + g) − (h + i);
#return result;

.text
.global main
main:
    addi s0,zero,0 #y
    addi a0,zero,2
    addi a1,zero,3
    addi a2,zero,4
    addi a3,zero,5
    jal ra,diffofsums
    add s0,a0,zero #y=result
    j exit

diffofsums:
    addi sp,sp,-12
    sw s3,8(sp)
    sw t0,4(sp)
    sw t1,0(sp)
    add t0,a0,a1
    add t1,a2,a3
    sub s3,t0,t1
    add a0,s3,zero
    lw s3,8(sp)
    lw t0,4(sp)
    lw t1,0(sp)
    addi sp,sp,12    
    jr ra
#t0 t1 s3 values remain unchanged
exit:j exit
                