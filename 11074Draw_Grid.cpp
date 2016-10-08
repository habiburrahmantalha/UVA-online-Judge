#include<stdio.h>

int s,t,n,l;

void print1()
{
    int i,j;
    for(i=0;i<t;i++)
    {
        for(j=0;j<l;j++)
        printf("*");
        printf("\n");
    }
}
void print2()
{
    int i,j,k;
    for(i=0;i<s;i++)
    {
        for(j=0;j<n;j++)
        {
            for(k=0;k<t;k++)
            printf("*");
            for(k=0;k<s;k++)
            printf(".");
        }
        for(k=0;k<t;k++)
            printf("*");
        printf("\n");
    }
}

int main()
{
    int i,tc=1;
    while(scanf("%d %d %d",&s,&t,&n) && s && t && n )
    {
        l=n*s+(n+1)*t;
        printf("Case %d:\n",tc++);
        for(i=0;i<n;i++)
        {
            print1();
            print2();
        }
        print1();
        printf("\n");

    }
    return 0;
}
