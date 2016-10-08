#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,t,s,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&s,&d);
        a=(s+d)/2;
        b=abs(a-d);

        if(a+b==s && abs(a-b)==d)
        printf("%d %d\n",a,b);
        else
        printf("impossible\n");
    }
    return 0;
}

