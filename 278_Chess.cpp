#include<stdio.h>

int main()
{
    int tc,r,c,d;
    char p[5];
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%s %d %d",p,&r,&c);
        if(p[0]=='r')
        {
            if(c<r)
                r=c;
            printf("%d\n",r);
        }
        else if(p[0]=='Q')
        {
            if(c<r)
                r=c;
            printf("%d\n",r);
        }
        else if(p[0]=='K')
        {
            if(r&1)
                r++;
            if(c&1)
                c++;
            printf("%d\n",(r*c)/4);
        }
        else
        {
            d=r*c;
            if(d&1)
                d++;
            printf("%d\n",d/2);
        }
    }
    return 0;
}
