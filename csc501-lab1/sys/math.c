#include <stdio.h>
#include<math.h>

double pow(double x, int y)
{
if(y==0)
{
	return(1.00);
}
else
{	double temp=x;
	int i;
	if(y>0)//if y is positive
	for (i=1; i<y;i++)
	{
		temp=temp*x;
	}
	else
	{ temp=1;
	for (i=0; i>y;i--)
	{
		temp=temp/x;
	}
	}
	return (temp);
}
}

double log(double x)
{
	double temp=0;
	int i;	
	for (i=1;i<=20;i++)
	{
		temp=temp+(pow(-1,i+1)*((pow(x-1,i))/i));
	}
	return (temp);

}

double expdev(double lambda) {
    double dummy;
    do
        dummy= (double) rand() / RAND_MAX;
       
    while (dummy == 0.0);
    return -log(dummy) / lambda;
}

