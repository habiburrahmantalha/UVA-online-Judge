#include<stdio.h>

int main()
{
    int num;
    while(scanf("%d",&num)==1)
    {
        int a=0,count=0;
        while(1)
        {
            a=(a*10+1)%num;
            count++;
            if(a<=0)
            break;
        }
        printf("%d\n",count);
    }
    return 0;
}
