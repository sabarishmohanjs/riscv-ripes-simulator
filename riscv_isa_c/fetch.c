#include "riscv.h"

//unsigned 32 bit instruction patterns 
//no sign extension for this pattern
//operations of shift right and others for decoding will be good
uint32_t fetch() 
{
    //memory is word aligned
    //pc counts by byte wise
    return instr_mem[pc/4];
}