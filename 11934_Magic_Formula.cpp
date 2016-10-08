#include<stdio.h>

int main()
{
    int a,b,c,d,l,count,i,s;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&d,&l))
    {
        if(a==0 && b==0 && c==0 && d==0 && l==0)
            break;
        count=0;
        for(i=0;i<=l;i++)
        {
            s=a*i*i+b*i+c;
            if(s%d==0)
                count++;
        }printf("%d\n",count);
    }
    return 0;
}
