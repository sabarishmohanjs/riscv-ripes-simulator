#include "riscv.h"
#include<string.h>

uint32_t instr_mem[INSTR_MEM]; //stores all the instructions
//word addressable memory = 4  bytes is used for
//instruction storage

int load_program(const char *filename) //reads the instructions from the file
{
    FILE *fp=fopen(filename,"r");
    if(fp==NULL)
    {
        perror("Error opening the file");
        return -1;
    }

    char line[256];
    int count=0;

    //fgets(destination,max size, file_pointer) - reads the line including the newline \n char
    //line - buffet register to store the data /instr here
    //sizeof(line) - retreives the max length
    //fp - file pointer
    while(fgets(line,sizeof(line),fp)!=NULL)  //it keep on reading the lines until there are no more lines
    {
        line[strcspn(line,"\n")]='\0';
        //strcspn - finds the first occurence of the char \n and returns the index of it
        // line[strcspn] --> line[10] ='\0' null terminator that marks the end of the string

        int len=strlen(line);
        for(int i=0;i<len;i+=10)
        {
            char byte_str[11]={0}; //initialising it to 0
            strncpy(byte_str,&line[i],10);
            //strncpy(dest,starting point in the line,number of characters to copy)
            //strcpy copies to the string without the bound checking
            //strncpy copies the string upto the number of characters declared
            //to avoid string issues we terminate the string using '\0'
            uint32_t value=(uint32_t)strtoul(byte_str,NULL,16);
            //strtoul - converts string to integer
            //byte_str - input string
            //NULL - ignore the leftover chars
            //16 - base hexadecimal
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
    //*filename is the pointer to the characters or string 
    //in the declared file name
    //const is used so that the strings cannot be modified
    //the instr is stored in ROM,modifying it will be an undefined behaviour
    //it depends on the purpose too 
    load_program(filename);
}