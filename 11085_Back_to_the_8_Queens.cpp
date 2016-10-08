#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdio.h>

using namespace std;
int x[10],Q[100][10],c;

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

int main()
{
    int i,j,mn,a[10],cost,t=1;
    c=0;
    NQueens(1,8);

    while(scanf("%d",&a[1])==1)
    {
        for(i=2;i<=8;i++)
            scanf("%d",&a[i]);
        mn=100000000;
        for(i=0;i<c;i++)
        {
            cost=0;
            for(j=1;j<=8;j++)
            {
                //printf("%d ",Q[i][j]);
                if(abs(Q[i][j]-a[j])!=0)
                cost++;

            }
            if(mn>cost)
                    mn=cost;
        }
        printf("Case %d: %d\n",t++,mn);

    }
    return 0;

}
