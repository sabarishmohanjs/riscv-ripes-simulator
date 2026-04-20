#include "riscv.h"

void get_operation(DecodedInstruction d)
{
    switch(d.opcode)
    {
        case 0x13: //i type
            switch(d.funct3)
            {
                case 0x0: //addi
                    reg[d.rd]=alu(reg[d.rs1],d.imm,OP_ADDI);
                break;
                case 0x1: //slli
                    reg[d.rd]=alu(reg[d.rs1],d.imm,OP_SLLI);
                break;
                case 0x2://slti
                    reg[d.rd]=alu(reg[d.rs1],d.imm,OP_SLTI);
                break;
                case 0x3: //sltiu
                    reg[d.rd]=alu(reg[d.rs1],d.imm,OP_SLTIU);
                break;
                case 0x4: //xori
                    reg[d.rd]=alu(reg[d.rs1],d.imm,OP_XORI);
                break;
                case 0x6: //ori
                    reg[d.rd]=alu(reg[d.rs1],d.imm,OP_ORI);
                break;
                case 0x7: //andi
                    reg[d.rd]=alu(reg[d.rs1],d.imm,OP_ANDI);
                break;
                case 0x5:
                    if(d.funct7==0x00) //srli
                    {
                        reg[d.rd]=alu(reg[d.rs1],d.imm,OP_SRLI);
                    }
                    else if(d.funct7==0x10) //srai
                    {
                        reg[d.rd]=alu(reg[d.rs1],d.imm,OP_SRAI);
                    }
                break; 
            }
            break;
        
        case 0x33://r type instr
            switch(d.funct3)
            {
                case 0x0:
                    if(d.funct7==0x00)//add
                    {
                        reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_ADD);
                    }
                    else if(d.funct7==0x20) //sub
                    {
                        reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_SUB);
                    }
                    break;
                case 0x1://sll
                    reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_SLL);
                break;
                case 0x2://slt
                    reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_SLT);
                break;
                case 0x3: //sltu
                    reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_SLTU);
                break;
                case 0x4: //xor
                    reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_XOR);
                break;
                case 0x5:
                    if(d.funct7==0x00) //srl
                    {
                        reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_SRL);
                    }
                    else if(d.funct7==0x20) //sra
                    {
                        reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_SRA);
                    }
                break;
                case 0x6: //or
                    reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_OR);
                break;
                case 0x7: //and
                    reg[d.rd]=alu(reg[d.rs1],reg[d.rs2],OP_AND);
                break;              
                
            }
            break;
        case 0x03 ://load
            switch(d.funct3)
            {
                case 0x00: //lb
                    reg[d.rd]=memory_load(reg[d.rs1] + d.imm,BYTE);
                break;
                case 0x01: //lh
                    reg[d.rd]=memory_load(reg[d.rs1] + d.imm,HALFWORD);
                break;
                case 0x02: //lw
                    reg[d.rd]=memory_load(reg[d.rs1] + d.imm,WORD);
                break;
                case 0x04:  //ld missing lbu
                    reg[d.rd]=memory_load(reg[d.rs1] + d.imm,SIGNED_BYTE); //check signed vs unsigned
                break;
                case 0x05: //lhu
                    reg[d.rd]=memory_load(reg[d.rs1] + d.imm,SIGNED_HALFWORD);
                break;
            }
            break;
        case 0x23 ://store type
            switch(d.funct3)
            {
                case 0x0: //sb
                    memory_store(reg[d.rs1] + d.imm, reg[d.rs2],BYTE);
                break;
                case 0x1: //sh
                    memory_store(reg[d.rs1] + d.imm, reg[d.rs2],HALFWORD);
                break;
                case 0x2: //sw
                    memory_store(reg[d.rs1] + d.imm, reg[d.rs2],WORD);
                break;

            }
            break;
        case 0x63: // b type pc handlin
            switch(d.funct3)
            {
                case 0x0://beq
                    if(alu(reg[d.rs1],reg[d.rs2],OP_BEQ))
                    {
                        pc=pc+d.imm;
                    }
                break;
                case 0x1: //bne
                    if(alu(reg[d.rs1],reg[d.rs2],OP_BNE))
                    {
                        pc=pc+d.imm;
                    }
                break;
                case 0x4: //blt
                    if(alu(reg[d.rs1],reg[d.rs2],OP_BLT))
                    {
                        pc=pc+d.imm;
                    }
                break;
                case 0x5: //bge
                    if(alu(reg[d.rs1],reg[d.rs2],OP_BGE))
                    {
                        pc=pc+d.imm;
                    }
                break;
                case 0x6: //bltu
                    if(alu(reg[d.rs1],reg[d.rs2],OP_BLTU))
                    {
                        pc=pc+d.imm;
                    }
                break;
                case 0x7: //bgeu
                    if(alu(reg[d.rs1],reg[d.rs2],OP_BGEU))
                    {
                        pc=pc+d.imm;
                    }
                break;
            }
            break;
        case 0x37: //lui
            reg[d.rd]=alu(0,d.imm,OP_LUI);
        break;
        case 0x17://auipc
            reg[d.rd]=alu(pc,d.imm,OP_AUIPC);
        break;
        case 0x6F: //jal
            reg[d.rd]=pc+4;
            pc=pc+d.imm;
        break;
        case 0x67: //jalr
            reg[d.rd]=pc+4;
            pc=(reg[d.rs1]+ d.imm) & ~1;
        break;
        default:
            break;     
            
            
    }
}