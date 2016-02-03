#include "srand.h"
#include<stdio.h>
int main()
{
	int i;
	for(i=0;i<100*100*100;i++)
	{
		printf("%d\n",(srand()+srand())%1000);
	}
	return 0;
}
