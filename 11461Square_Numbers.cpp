#include<stdio.h>
#include<string.h>

int square[100001];

void sqn()
{
    int in=1;
    memset(square,0,sizeof(square));
    for(int i=1;i*i<=100000;i++)
    square[i*i]=in++;

//for(int i=1;i<=1000;i++)
//if(square[i])
//printf("%d ",square[i]);

}

int main()
{
    sqn();
    int a,b,i,j;
    while(scanf("%d %d",&a,&b) && a && b)
    {
            for(i=a;i>=0;i--)
            if(square[i]!=0)
            break;
            //printf("%d ",square[i]);
            for(j=b;j>=0;j--)
            if(square[j]!=0)
            break;
            //printf("%d ",square[j]);
            if(i==a)
            printf("%d\n",square[j]-square[i]+1);
            else
            printf("%d\n",square[j]-square[i]);
    }

    return 0;
}
