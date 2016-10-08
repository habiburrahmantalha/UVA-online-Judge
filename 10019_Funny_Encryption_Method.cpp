#include<stdio.h>

int hex[]={0,1,1,2,1,2,2,3,1,2};

int binary(int m)
{
    int count=0;

    while(m)
    {
        if(m%2==1)
            count++;
        m/=2;
    }
    return count;
}
int hex_bin(int m)
{
    int sum=0;

    while(m)
    {
        sum+=hex[m%10];
        m/=10;
    }
    return sum;
}
int main()
{
    int n,m,b1,b2;
    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&m);

        b1=binary(m);

        b2=hex_bin(m);

        printf("%d %d\n",b1,b2);
    }
    return 0;
}
