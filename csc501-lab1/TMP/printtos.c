#include <stdio.h>

static unsigned long    *esp;
static unsigned long    *ebp;


void printtos()
{
        
        unsigned long   *sp, *fp;
	int i=500;
        int k=1001;
int g=90;

                asm("movl %esp,esp");
                asm("movl %ebp,ebp");
                sp = esp;
                fp = ebp;
printf("Before [0x%08X]: 0x%08X\n ",&fp+2,fp+2);

printf("After [0x%08X]: 0x%08X\n",&sp,sp);

//printf("Current Base pointer: %x\n ",fp);
 k=i+2;
i=1;
                for (; sp < fp; sp++)
                    { if(i<5)
{   printf("\t element[0x%08X]: 0x%08X \n", sp, *sp);
i++;}
                }



}
