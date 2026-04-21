#include"riscv.h"

//return type is signed since the values can be negative
int32_t alu(int32_t op1, int32_t op2, operations op) 
{
    switch(op)
    {
        case OP_ADD:
            return op1+op2;
        case OP_ADDI:
            return op1+op2;
        case OP_SUB:
            return op1-op2;
        case OP_SLL:
            return op1<<(op2 & 0x1F); //bit wise or logical and 
            //the shifting connstant is 5 bits
        case OP_SLLI:
            return op1<<(op2 & 0x1F);
        case OP_SLT:
            return (op1<op2)?1:0;
        case OP_SLTI:
            return (op1<op2)?1:0;
        case OP_SLTU:
            return ((uint32_t)op1 < (uint32_t)op2)?1:0;
        case OP_SLTIU:
            return ((uint32_t)op1 < (uint32_t)op2)?1:0;
        case OP_XOR:
            return op1 ^ op2;
        case OP_XORI:
            return op1 ^ op2;
        case OP_OR:
            return op1 | op2;
        case OP_ORI:
            return op1 | op2;
        case OP_AND:
            return op1 & op2;
        case OP_ANDI:
            return op1 & op2;
        case OP_SRL:
            return (uint32_t)op1 >> (op2 & 0x1F); //sra fills with 0s
        case OP_SRLI:
            return (uint32_t)op1 >> (op2 & 0x1F);
        case OP_SRA:
            return op1 >> (op2 & 0x1F); //signed bits extends
        case OP_SRAI:
            return op1 >> (op2 & 0x1F);
        case OP_LUI: //stores upper 20 bits and the lower bits are 0s
            return op2;
        case OP_AUIPC: //pc relative addressing
            return op1+op2;
        case OP_BEQ:
            return (op1==op2)?1:0;
        case OP_BNE:
            return (op1!=op2)?1:0;
        case OP_BLT:
            return (op1<op2)?1:0;
        case OP_BGE:
            return (op1>=op2)?1:0;
        case OP_BLTU:
            return ((uint32_t)op1 < (uint32_t)op2)?1:0;
        case OP_BGEU:
            return ((uint32_t)op1 >= (uint32_t)op2)?1:0;
        default:
            return 0;
    }
}