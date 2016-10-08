#include<stdio.h>
#include<math.h>

int main()
{
    long double res,a0,an,c;
    int T,i,n;
    scanf("%d",&T);
    while(T--)
    {
        res=0;
        scanf("%d",&n);
        scanf("%Lf",&a0);
        scanf("%Lf",&an);
        for(i=0;i<n;i++)
        {
            scanf("%Lf",&c);
            res-=c*2;
        }
        res+=a0+an;
        if(n==1)
            res/=2;
        printf("%.2Lf\n",res);

    }
    return 0;
}
