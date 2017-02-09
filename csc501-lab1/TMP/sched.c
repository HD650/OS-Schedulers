#include<stdio.h>
#include<sched.h>

int schedulerClass;

void setschedclass (int sched_class)
{
schedulerClass=sched_class;
}
int getschedclass()
{

return(schedulerClass);
}
