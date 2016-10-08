#include<stdio.h>
#define N 1000010

int a[N]={0},D[N]={0};
void divisor()
{
    int i,j,x,y;
    for ( i = 1; i <N; i++ )
	{
		for ( j = i; j <N; j+=i )
			a[j]+=1;
	}
	x=a[1];
	y=1;
	for(i=1;i<N;i++)
    {
        if(a[i]>=x)
        {
            x=a[i];
            y=i;
            //D[i]=y;
        }
        D[i]=y;
    }
}

int main()
{
    int tc,i,n,x,y;
    divisor();
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        //x=0;
        //for(i=0;i<=n;i++)
        {
            //if(a[i]>=x)
            {
                //x=a[i];
               // y=i;
            }
        }
        printf("%d\n",D[n]);
    }
    return 0;
}
