#include<stdio.h>

double min(double a,double b)
{
    if(a<b)
        return a;
    else
        return b;
}
int main()
{
    double n,r,ans,i,j;

    while(scanf("%lf %lf",&n,&r))
    {
        if(n==0 && r==0)
            break;
        if(r==0)
        {
            printf("1\n");
            continue;
        }
        r=min(r,n-r);
        ans=1.0;
        for(i=r;i>=1;i--)
        {
            ans*=(n-i+1)/i;
        }

        printf("%.0lf\n",ans);
    }
    return 0;

}
