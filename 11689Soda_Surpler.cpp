#include<stdio.h>

int main()
{
    int tc,n,e,f,c,soda;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&e,&f,&c);
        n=e+f;
        soda=0;
        while(n>=c)
        {
            e=n/c;
            soda+=e;
            n%=c;
            n+=e;
        }
        printf("%d\n",soda);
    }
    return 0;
}
