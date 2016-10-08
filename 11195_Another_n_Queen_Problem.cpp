//whats wrong X( ?
#include<iostream>
#include<math.h>
#define R 50
#include<algorithm>
#include<stdio.h>
using namespace std;
int x[R],c,a,b;
char g[20][20];
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



				    c++;
                    //printf("%2d      ",c);
				    for(j=1;j<=n-1;j++)
                        cout<<x[j]<<" ";
                    cout<<x[j]<<endl;

			}
			else if(g[k+1][i-1]=='.')
                NQueens(k+1,n);
		}
	}
}

int main()
{
	int n,i,t=1;

    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)
            scanf("%s",g[i]);

        c=0;

        NQueens(1,n);
        printf("Case %d: %d\n",t++,c);
    }
	return 0;
}
