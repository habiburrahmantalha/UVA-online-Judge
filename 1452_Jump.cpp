#include<stdio.h>

int josephus(int n,int k,int m)
{
    if(n==m)
        return 0;
    else
        return (josephus(n-1,k,m)+k)%n;
}

int main()
{
    int n,k,x;

    while(scanf("%d %d",&n,&k)==2 && n+k)
    {
        x=0;
        for(int i=1;i<=n;i++)
        {x=(x+k)%i;
        printf("%d\n",x);}
        //printf("%d %d %d\n",josephus(n,k,9)+1,josephus(n,k,10)+1,josephus(n,k,1)+1);
    }
    return 0;
}
