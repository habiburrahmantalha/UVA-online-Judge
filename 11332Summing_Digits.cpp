#include<stdio.h>

int sum_digit(int n)
{
    int x=0;
    if(n<10)
    return n;
    while(n)
    {
        x+=n%10;
        n/=10;
    }
    return sum_digit(x);
}


int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        printf("%d\n",sum_digit(n));
    }
    return 0;
}
