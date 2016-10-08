#include<stdio.h>
#include<string.h>
int main()
{
    int tc,t=1,j,x,n,y[101];
    bool stable;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);

        stable=true;
        memset(y,0,sizeof(y));
        j=n*n;
        while(j--)
        {
                scanf("%d",&x);
                if(stable)
                {
                    y[x]++;
                    if(y[x]>n)
                    stable=false;
                }
        }
        if(stable)
                printf("Case %d: yes\n",t++);
        else
            printf("Case %d: no\n",t++);
    }
    return 0;
}
