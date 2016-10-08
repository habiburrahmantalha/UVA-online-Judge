#include<stdio.h>

int main()
{
    int tc=1,n,i,p_c[13],p_n;
    while(scanf("%d",&n) && n>=0)
    {
        printf("Case %d:\n",tc++);
        for(i=0;i<12;i++)
        scanf("%d",&p_c[i]);

        for(i=0;i<12;i++)
        {
            scanf("%d",&p_n);
            if(p_n<=n)
            {
                printf("No problem! :D\n");
                n-=p_n;
            }
            else
            printf("No problem. :(\n");


            n+=p_c[i];
        }
    }
    return 0;
}
