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
struct winshift
{
        int left;
        int right;
}win;

int frameselect(int *arr,int n)
{
        int high1=*max_element(arr,arr+n);
        /*for(int i=n;i<LOOP;i++)
        {
                if(arr[i]>high1)
                return arr[i];
        }
        return arr[LOOP-1];
	*/
	return high1;
}
int winselect(int *arr,int frame,int winsize,int remaining)
{
	int temp,max;
	win.left=0;
	win.right=winsize-1;
	if(winsize>remaining)
		win.right=remaining;
	while(win.right<LOOP)
	{
		max=*max_element(arr+win.left,arr+win.right+1);
		if(arr[win.left]==max && arr[win.left]>frame)
			break;
		else
		{
			temp=win.left;
			while(arr[temp]!=max)
				temp++;
			if(arr[win.left]==max)
				win.left++;//shift 1 jab loop fansh jaye
			else
				win.left=temp;
			win.right=win.left+winsize-1;
		}
	}
	if(arr[win.left]>frame)
		return arr[win.left];
	else
		return max;		
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
	int i,f,highest,p,frame,window,winsize;
	int score[LOOP];
	bool flag[SAMPLE];
	float prob;
//	for(i=0;i<LOOP;i++)
//	cin>>score[i];
	winsize=50;
	for(f=1;f<LOOP;f++)
	{
		for(p=0;p<SAMPLE;p++)
		{
		        for(i=0;i<LOOP;i++)
        		cin>>score[i];
			frame=frameselect(score,f);
			window=winselect(score+f,frame,winsize,LOOP-f);
			highest=*max_element(score,score+LOOP);
			if(window==highest)
				flag[p]=1;
			else
				flag[p]=0;
		}
                prob=float(countone(flag))/SAMPLE;
                cout<<f<<' '<<prob<<endl;
	}				
}
