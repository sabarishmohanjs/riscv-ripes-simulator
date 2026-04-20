#include "riscv.h"

IType DecodeI(uint32_t instr)
{
    //IType is the return type
    // since each data cannot be returned individually
    // all the values of specific data type is combined into one box - struct
    //the struct is returned
    //local box is created to store decoded values before returning
    IType i;
    i.opcode = instr & 0x7F; //last 7 bits
    i.rd = (instr>>7) & 0x1F; //5 bits
    i.funct3 =(instr>>12) & 0x7;//3 bits
    i.rs1 = (instr>>15) & 0x1F; //5 bits
    i.imm = (int32_t)(instr & 0xFFF00000)>>20; //12 bits
    return i;
}

RType DecodeR(uint32_t instr)
{
    RType r;
    r.opcode = instr & 0x7F; //last 7 bits
    r.rd = (instr>>7) & 0x1F; //5 bits
    r.funct3 =(instr>>12) & 0x7;//3 bits
    r.rs1 = (instr>>15) & 0x1F; //5 bits   
    r.rs2 = (instr>>20) & 0x1F; //5 bits
    r.funct7 = (instr>>25) & 0x7F; //last 7 bits
    return r;
}

SType DecodeS(uint32_t instr)
{
    SType s;
    s.opcode = instr & 0x7F; //last 7 bits
    s.funct3 =(instr>>12) & 0x7;//3 bits
    s.rs1 = (instr>>15) & 0x1F; //5 bits   
    s.rs2 = (instr>>20) & 0x1F; //5 bits   
    s.imm = (int32_t)(((instr>>25)<<5) | ((instr>>7) & 0x1F))<<20>>20; //sign extend msb 20 bits as imm is 12 bits
    return s;
}

UType DecodeU(uint32_t instr)
{
    UType u;
    u.opcode = instr & 0x7F; // 7 bits
    u.rd = (instr>>7) & 0x1F; //5 bits
    u.imm = (int32_t)(instr & 0xFFFFF000); //imm upper 20 bits
    return u;
}

JType DecodeJ(uint32_t instr)
{
    JType j;
    j.opcode = instr & 0x7F; // 7 bits
    j.rd = (instr>>7) & 0x1F; //5 bits
    j.imm = (int32_t)((instr & 0x80000000)? 0xFFF00000 : 0) | ((instr>>20) & 0x7FE) | ((instr>>9) & 0x800) | ((instr>>12) & 0xFF );
    return j;
}

DecodedInstruction decode(uint32_t instr) //used for the creation and execution using one uniform format
{
    DecodedInstruction d;
    uint32_t opcode = instr & 0x7F; //extraction of the opcode

    switch(opcode)
    {
        case 0x13: //addi
        case 0x03: // load
        {
            IType i= DecodeI(instr);
            d.opcode = i.opcode;
            d.rd = i.rd;
            d.funct3 = i.funct3;
            d.rs1 = i.rs1;
            d.rs2 = 0 ;
            d.funct7 = 0;
            d.imm = i.imm;
        }
        break;
        case 0x33:// r type
        {
            RType r = DecodeR(instr);
            d.opcode = r.opcode;
            d.rd = r.rd;
            d.funct3 = r.funct3;
            d.rs1 = r.rs1;
            d.rs2 = r.rs2;
            d.funct7 = r.funct7;
            d.imm = 0;
        }
        break;
        case 0x23: // s type
        {
            SType s = DecodeS(instr);
            d.opcode = s.opcode;
            d.rd = 0;
            d.funct3 = s.funct3;
            d.rs1 = s.rs1;
            d.rs2 = s.rs2; 
            d.funct7 = 0;
            d.imm = s.imm;
        }
        break;
        case 0x37://u type - lui
        case 0x17://u type - auipc
        {
            UType u = DecodeU(instr);
            d.opcode = u.opcode;
            d.rd = u.rd;
            d.funct3 = 0;
            d.rs1 = 0; 
            d.rs2 = 0;
            d.funct7 = 0;
            d.imm = u.imm;
        }
        break;
        case 0x6F:
        {
            JType j = DecodeJ(instr);
            d.opcode = j.opcode;
            d.rd = j.rd;
            d.funct3 = 0;
            d.rs1 = 0; 
            d.rs2 = 0;
            d.funct7 = 0;
            d.imm = j.imm;
        }
        break;
        default:
            d.opcode = opcode;
            d.rd = 0;
            d.funct3 = 0;
            d.rs1 = 0; 
            d.rs2 = 0;
            d.funct7 = 0;
            d.imm = 0;
    }
    return d;
}