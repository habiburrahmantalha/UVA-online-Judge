#include<stdio.h>

int main()
{
    int n,x,t=1,i,c;
    while(scanf("%d",&n) && n)
    {
        c=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==0)
                c++;
        }
        printf("Case %d: %d\n",t++,n-c-c);
    }
    return 0;
}
