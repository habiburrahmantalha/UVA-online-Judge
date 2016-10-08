#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>

using namespace std;
int x[10],Q[100][10],c,g[10][10];

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
		if(place(k,i)==1)
		{
			x[k]=i;
			if(k==n)
			{
                for(j=1;j<=n;j++)
                    Q[c][j]=x[j];
                 c++;

			}
			else NQueens(k+1,n);
		}
	}
}
int MAXIMUM()
{
    int MAX=0,i,j,res;
    for(i=0;i<c;i++)
    {
        res=0;
        for(j=1;j<=8;j++)
        {
            res+=g[j][Q[i][j]];
        }
        MAX=max(MAX,res);
    }
    return MAX;
}
int main()
{
    c=0;
    NQueens(1,8);
	int tc,i,j;
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=1;i<=8;i++)
            for(j=1;j<=8;j++)
                scanf("%d",&g[i][j]);
        printf("%5d\n",MAXIMUM());

    }
	return 0;
}
