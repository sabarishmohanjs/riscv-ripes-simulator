main:
    addi a0, zero, 5     # a0 = 5 (argument)
    jal ra, factorial    # call factorial(5)
    add s0, a0, zero     # store result in s0

    loop:                # infinite loop to stop execution
        jal zero, loop

factorial:
    addi sp, sp, -8      # allocate stack space
    sw ra, 4(sp)         # save return address
    sw a0, 0(sp)         # save argument (n)

    li t0, 1             # t0 = 1
    ble a0, t0, base     # if n <= 1, go to base

    addi a0, a0, -1      # a0 = n - 1
    jal ra, factorial    # recursive call: factorial(n - 1)
    
    lw t1, 0(sp)         # restore original n
    mul a0, a0, t1       # result = n * factorial(n - 1)
    j ret

base:
    li a0, 1             # return 1

ret:
    lw ra, 4(sp)         # restore return address
    addi sp, sp, 8       # deallocate stack
    jr ra                # return
