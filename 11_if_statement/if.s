#if (apples = = oranges)
#f = g + h;
#apples = oranges − h;

addi s0,zero,5 #apples
addi s1,zero,10 #oranges
addi s2,zero,20 #g
addi s3,zero,30 #h
bne s0,s1,l1
add s4,s2,s3
l1: sub s5,s1,s3


