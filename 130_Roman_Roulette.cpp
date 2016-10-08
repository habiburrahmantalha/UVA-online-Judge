#include<stdio.h>

int josephus(int n,int k)
{
    if(n==1)
        return 0;
    else
        return (josephus(n-1,k)+k)%n;
}

int main()
{
    int n,k,x;

    while(scanf("%d %d",&n,&k)==2 && n+k)
    {
        x = josephus(n,k)+1;

            printf("%d\n",x);
    }
    return 0;
}
