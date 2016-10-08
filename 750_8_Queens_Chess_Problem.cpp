#include<iostream>
#include<math.h>
#define R 50
#include<algorithm>
#include<stdio.h>
using namespace std;
int x[R],c,a,b;

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

                if(x[b]==a)
				{
				    c++;
                    printf("%2d      ",c);
				    for(j=1;j<=n-1;j++)
                        cout<<x[j]<<" ";
                    cout<<x[j]<<endl;
				}
			}
			else NQueens(k+1,n);
		}
	}
}

int main()
{
	int n,tc;
	bool f=false;
    scanf("%d",&tc);
    while(tc--)
    {
        if(f)
            printf("\n");
        n=8;
        c=0;
        scanf("%d %d",&a,&b);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        NQueens(1,n);
        f=true;
    }
	return 0;
}
