#include "riscv.h"

uint32_t memory[MEMORY];

int32_t memory_load(uint32_t addr, operations op)
{
    if (addr>=MEMORY)
    {
        return 0;
    }

    switch(op)
    {
        case BYTE:
            return (int8_t)memory[addr];
        case HALFWORD:
            if (addr + 1 >= MEMORY) return 0;
            return (int16_t)(memory[addr] | (memory[addr+1]<<8));
        case WORD:
            if (addr + 3 >= MEMORY) return 0;
            return (int32_t)(memory[addr] | (memory[addr+1]<<8) | (memory[addr+2]<<16) | (memory[addr+3]<<24));
        case SIGNED_BYTE:
            return (uint8_t)memory[addr];
        case SIGNED_HALFWORD:
            if (addr + 1 >= MEMORY) return 0;
            return (uint16_t)(memory[addr] | (memory[addr+1]<<8));
        default:
            return 0;
    }
};

void memory_store(uint32_t addr, int32_t data , operations op)
{
    if (addr>=MEMORY)
    {
        return;
    }

    switch(op)
    {
        case BYTE:
            memory[addr]=(uint8_t)data;
            break;
        case HALFWORD:
            if(addr + 1>= MEMORY) return;
            memory[addr]=(uint8_t)data;
            memory[addr+1]=(uint8_t)(data>>8);
            break;
        case WORD:
            if(addr + 3>= MEMORY) return;
            memory[addr]=(uint8_t)data;
            memory[addr+1]=(uint8_t)(data>>8);
            memory[addr+2]=(uint8_t)(data>>16);
            memory[addr+3]=(uint8_t)(data>>24);
            break;
        default:
            return;
    }
}