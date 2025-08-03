.data
b: .word 10
c: .word 5
g: .word 30
h: .word 50 
i: .word 15
j: .word 25

out_a: .word 0
out_f: .word 0

.text
.global _start

_start:
    
    lw s0 b
    lw s1 c
    lw s2 g
    lw s3 h
    lw s4 i
    lw s5 j
    
    sub s6 s0 s1 #a=b-c
    
    add t0 s2 s3 #t0=g+h
    add t1 s4 s5 #t1=i+j
    sub s7 t0 t1 #f=t0-t1
    
    la t2 out_a
    sw s6 0(t2)
    
    la t3 out_f
    sw s7 0(t3)

end:
    j end
    
    
 
