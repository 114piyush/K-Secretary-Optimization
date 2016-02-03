//variable window and fixed N problem
//plot between "window size" and probability 
#include<iostream>
#include<algorithm>
#include<math.h>
#include "srand.h"
using namespace std;
#define N 100
#define SAMPLE 100
struct winshift
{
	int left;
	int right;
}win;

int winsize=4;

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
	int i,score[N],max,p,highest,cost,temp,n;
	bool flag[SAMPLE];
	float prob;
	n=N;
	float c;
	for(c=0;c<1;c+=0.05)
	{	
		winsize=c*n;
		for(p=0;p<SAMPLE;p++)
		{
			for(i=0;i<n;i++)
			cin>>score[i];
			//score[i]=(srand()+srand())%1000;	
			win.left=0;
			win.right=winsize-1;
			highest=*max_element(score,score+n);
			if(n<winsize)
				cost=highest;
			else
			{
				while(win.right<n)
				{
				max=*max_element(score+win.left,score+win.right+1);
				if(score[win.left]==max)
				break;
				else
				{
				temp=win.left;
				while(score[temp]!=max)
					temp++;
				win.left=temp;
				win.right=win.left+winsize-1;
				}
				}
				cost=score[win.left];
			}
			if(cost==highest)
				flag[p]=1;
			else
				flag[p]=0;
		}
		prob=float(countone(flag))/SAMPLE;
		cout<<c<<' '<<prob<<endl;
	}
}
		
			
		
