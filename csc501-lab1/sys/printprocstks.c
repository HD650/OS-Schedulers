
#include<stdio.h>

#include<kernel.h>
#include<proc.h>
static unsigned long    *esp;
void printprocstks(int priority)
{
struct pentry *proc ;


int i;
//printf("Number of processes :%d\n",numproc);
for (i=0;i<NPROC;i++)
{
proc=&proctab[i];
if((proc)->pprio>priority)//if priority is larger than the parameter
{
printf("Process [%s]\n",(proc)->pname);
printf("\t pid: %d\n",i);

printf("\t priority: %d\n",(proc)->pprio);
printf("\t base: 0x%08X\n",(proc)->pbase);
printf("\t limit: 0x%08X\n",(proc)->plimit);
printf("\t len: %d\n",(proc)->pstklen);
if(i==currpid)
{
asm("movl %esp,esp");
printf("\t pointer: 0x%08X\n",esp);

}
else
{
printf("\t pointer: 0x%08X\n",(proc)->pesp);
}
}
}
}
