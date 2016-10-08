//backtracking is not going to work
#include<iostream>
#include<math.h>
#define R 50
#include<algorithm>
#include<stdio.h>
using namespace std;
int x[R];
bool f;
int place(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
	{
		if( x[j]==i || abs(x[j]-i)==abs(j-k) )
			return 0;
	}
	return 1;
}
void NQueens(int k,int n)
{
	int i,j;
	for(i=1;i<=n;i++)
	{
	    if(f)
            return;
		if(place(k,i)==1)
		{
			x[k]=i;
			if(k==n)
			{
                for(j=1;j<=n-1;j++)
                    printf("%d ",x[j]);
                printf("%d\n",x[j]);
                f=true;
                return;
			}
			else NQueens(k+1,n);
		}
	}
}

int main()
{
	int n;

    while(scanf("%d",&n)==1)
    {
        f=false;
        NQueens(1,n);
    }
	return 0;
}

