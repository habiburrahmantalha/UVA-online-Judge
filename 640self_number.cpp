#include<stdio.h>
#include<stdlib.h>
#define N 1000001

bool *self=(bool*)calloc(N, 1);

int main()
{
    int i,y,sum;
    for(i=1;i<N;i++)
		self[i]=1;

    for(i=1;i<N;i++)
    {
        sum=0;
        y=i;
        sum+=y;
        while(y)
        {
            sum+=y%10;
            y/=10;
        }
        self[sum]=0;
    }
    for(i=0;i<N;i++)
    if(self[i])
    printf("%d\n",i);
    return 0;
}
