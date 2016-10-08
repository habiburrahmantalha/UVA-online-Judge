#include<stdio.h>

int main()
{
    int tc,t=1,a,b,c;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a<=20 && b<=20 && c<=20)
        printf("Case %d: good\n",t++);
        else
        printf("Case %d: bad\n",t++);
    }
    return 0;
}
