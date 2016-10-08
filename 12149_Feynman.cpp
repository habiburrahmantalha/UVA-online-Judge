#include<stdio.h>

int main()
{
    int x;
    while(scanf("%d",&x) && x)
    {
        printf("%d\n",x*(x+1)*(2*x+1)/6);
    }
    return 0;
}
