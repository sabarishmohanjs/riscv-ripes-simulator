#include "riscv.h"
#include<string.h>

uint32_t instr_mem[INSTR_MEM];

int load_program(const char *filename)
{
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("Error opening the file");
        return -1;
    }

    char line[256];
    int count=0;

    while(fgets(line,sizeof(line),fp)!=NULL)
    {
        line[strcspn(line,"\n")]='\0';

        int len=strlen(line);
        for(int i=0;i<len;i+=10)
        {
            char byte_str[11]={0};
            strncpy(byte_str,&line[i],10);

            uint32_t value=(uint32_t)strtoul(byte_str,NULL,16);
            instr_mem[count]=value;
            count++;
        }
    }
    fclose(fp);
    return 0;
}

void instr_dump()
{
    const char *filename="example.hex";
    load_program(filename);
}