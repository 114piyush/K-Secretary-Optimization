#include<iostream>
#include<algorithm>
#include<cmath>
#include "srand.h"
using namespace std;
#define N 100
#define ITR 100
#define E exp(1.0)
int score[ITR][N];
int highest[ITR];
int classical(int *arr,int n)
{
	int high1=*max_element(arr,arr+int(n/E));
	for(int i=int(n/E);i<n;i++)
	{	
		if(arr[i]>high1)
		return arr[i];
	}
	return arr[n-1];
}
int countone(bool *a)
{
	int i,count=0;
	for(i=0;i<ITR;i++)
	{
	if(a[i]==1)
		count++;
	}
	return count;
}
	
int main()
{
	int i,j,classical_high,n;
	bool temp[ITR];
	float prob;
for(n=1;n<N;n++)
{
	for(i=0;i<ITR;i++)
	{
		for(j=0;j<n;j++)
		score[i][j]=(srand()+srand())%1000;
	//	for(j=0;j<N;j++)
	//	cout<<score[i][j]<<" ";
	//	cout<<endl;
	//	cout<<*max_element(*score+N*i,*score+N*(i+1))<<endl;
		highest[i]=*max_element(*score+n*i,*score+n*(i+1));	
		classical_high=classical(*score+n*i,n);
	//	cout<<classical_high<<endl;
		if(classical_high==highest[i])
			temp[i]=1;
		else
			temp[i]=0;
		
	}
	prob=float(countone(temp))/ITR;
	printf("%d %f\n",n,prob);
}
}
