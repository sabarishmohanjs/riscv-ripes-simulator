#a=b+c-d  10+5-3
#a-->s0
#b-->s1
#c-->s2
#d-->s3

addi s1 zero 10
addi s2 zero 5
addi s3 zero 3
add t0 s1 s2 # use of temporary reg
sub s0 t0 s3

