//Not classical but we vary frame which in n/e size of in classical
//plot between "frame size" and probability
#include<iostream>
#include<algorithm>
#include "srand.h"
#include<math.h>
using namespace std;
#define N 100
#define LOOP 100
#define SAMPLE 100
#define E exp(1.0)
int frameselect(int *arr,int n)
{
        int high1=*max_element(arr,arr+n);
        for(int i=n;i<LOOP;i++)
        {
                if(arr[i]>high1)
                return arr[i];
        }
        return arr[LOOP-1];
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
	int i,j,highest,n,p,frame;
	int score[LOOP];
	bool flag[SAMPLE];
	float prob;
	for(n=1;n<LOOP;n++)
	{
		for(p=0;p<SAMPLE;p++)
		{
			for(i=0;i<LOOP;i++)
			cin>>score[i];
		//	score[i]=(srand()+srand())%1000;
			highest=*max_element(score,score+LOOP);
			frame=frameselect(score,n);
			if(highest==frame)	
				flag[p]=1;
			else
				flag[p]=0;
		}
		prob=float(countone(flag))/SAMPLE;
		cout<<n<<' '<<prob<<endl;
	}
}
