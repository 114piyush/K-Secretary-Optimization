//classical problem
//classical plot graph between N and probability
//graph will constant at give 37% value
#include<iostream>
#include<algorithm>
#include "srand.h"
#include<math.h>
using namespace std;
#define N 100
#define LOOP 100
#define SAMPLE 100
#define E exp(1.0)
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
        for(i=0;i<SAMPLE;i++)
        {
        if(a[i]==1)
                count++;
        }
        return count;
}

int main()
{
	int i,j,highest,n,p,classic;
	int score[LOOP];
	bool flag[SAMPLE];
	float prob;
	for(n=1;n<LOOP;n++)
	{
		for(p=0;p<SAMPLE;p++)
		{
			for(i=0;i<n;i++)
			cin>>score[i];
		//	score[i]=(srand()+srand())%1000;
			highest=*max_element(score,score+n);
			classic=classical(score,n);
			if(highest==classic)	
				flag[p]=1;
			else
				flag[p]=0;
		}
		prob=float(countone(flag))/SAMPLE;
		cout<<n<<' '<<prob<<endl;
	}
}
