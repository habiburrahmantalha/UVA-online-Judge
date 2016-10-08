#include<stdio.h>

int main()
{
    int n,m,i,t=1;
    while(scanf("%d %d",&n,&m) && n&& m)
    {
        for(i=0;i<=26;i++)
        {
            if(n<=m+m*i)
                break;
        }
        if(i==27)
            printf("Case %d: impossible\n",t++);
        else
            printf("Case %d: %d\n",t++,i);
    }
    return 0;
}
