#include "riscv.h"

uint32_t pc=0;

int main()
{
    instr_dump(); //dump the instr 
    //the function is in instr_mem to fetch the instr from the files
    while (pc<MEMORY+4)
    {
        uint32_t instr=fetch();
        DecodedInstruction d= decode(instr);
        get_operation(d); //in the main.c code
        pc+=4;

    }
    printf("Register Content\n");
    for(int i=0;i<=31;i++)
    {
        printf("x%d = %d\n",i,reg[i]);
    }

    printf("memory \n");
    for(int i=0;i<MEMORY;i++)
    {
        printf("memory_loc[%d] = %d\n",i,memory[i]);

    }
    return 0;
}