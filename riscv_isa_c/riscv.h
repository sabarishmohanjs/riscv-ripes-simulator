#ifndef RISC_V_H //header guard start - prevents duplicate inclusion of classes for ex
#define RISC_V_H


#include<stdio.h> //std input and output functions
#include<stdlib.h> // for the purpose of memory alloc
#include<stdint.h> //declaration of unsigned int types

//compile time constants, no memory usage
#define INSTR_MEM 512 //512 entries
#define MEMORY 512
#define REGISTER 32 //32 regs


// defines a set of named constants - enum
// gives shorter alias name - typedef
typedef enum{
    OP_ADD,
    OP_ADDI,
    OP_SUB,
    OP_SLL,
    OP_SLLI,
    OP_SLT,
    OP_SLTI,
    OP_SLTU,
    OP_SLTIU,
    OP_XOR,
    OP_XORI,
    OP_OR,
    OP_ORI,
    OP_AND,
    OP_ANDI,
    OP_SRL,
    OP_SRLI,
    OP_SRA,
    OP_SRAI,
    OP_LUI,
    OP_AUIPC,
    OP_BEQ,
    OP_BNE,
    OP_BLT,
    OP_BGE,
    OP_BLTU,
    OP_BGEU,
    BYTE,
    HALFWORD,
    WORD,
    SIGNED_BYTE,
    SIGNED_HALFWORD,
    OP_UNKNOWN
}operations;

//COMMON FIELD FOR ALL INSTRUCTIONS 


typedef struct
{
    //using 8 bit int for fileds except imm
    //32 bit int for imm
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;
    int32_t imm;
}DecodedInstruction; //common for all the instructions

typedef struct
{
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;
    //int32_t imm; 
}RType; // rtype instr

typedef struct
{
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    //uint8_t rs2;
    //uint8_t funct7;
    int32_t imm;
}IType; //i type instr

typedef struct
{
    uint8_t opcode;
    //uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    //uint8_t funct7;
    int32_t imm;
}SType; // s type instr

typedef struct
{
    uint8_t opcode;
    //uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    //uint8_t funct7;
    int32_t imm;
}BType; // b type instr

typedef struct
{
    uint8_t opcode;
    uint8_t rd;
    // uint8_t funct3;
    // uint8_t rs1;
    // uint8_t rs2;
    // uint8_t funct7;
    int32_t imm;
}UType; //u type instr

typedef struct
{
    uint8_t opcode;
    uint8_t rd;
    // uint8_t funct3;
    // uint8_t rs1;
    // uint8_t rs2;
    // uint8_t funct7;
    int32_t imm;
}JType; // j type instr

//memory and register
// extern - global variable, accessed across the files
extern uint32_t instr_mem[INSTR_MEM];
extern uint32_t memory[MEMORY];
extern int32_t reg[REGISTER];
extern uint32_t pc;

//functions prototype
uint32_t fetch();  //fetch the instr from the instruction memory
DecodedInstruction decode(uint32_t instr); //decode the binary instruction into fields
void get_operation(DecodedInstruction d); //determine the operation type from decoded instr
int32_t alu(int32_t rs1, int32_t rs2, operations op); //alu operations
void instr_dump();
void memory_store(uint32_t addr, int32_t data, operations op); //load into the mem
int32_t memory_load(uint32_t addr, operations op); //store into the mem

#endif //end of header guard


