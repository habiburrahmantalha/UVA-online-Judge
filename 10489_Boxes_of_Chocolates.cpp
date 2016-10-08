#include<stdio.h>

int main()
{
    int i,j,m,n,x,res,tc,b,r;
    scanf("%d",&tc);

    while(tc--)
    {
        res=0;

        scanf("%d %d",&m,&b);
        for(i=0;i<b;i++)
        {
            r=1;
            scanf("%d",&n);
            for(j=0;j<n;j++)
            {
                scanf("%d",&x);
                r*=x;
                r%=m;
            }
            res+=r;
            res%=m;
        }
        printf("%d\n",res);
    }
    return 0;
}
