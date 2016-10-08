#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
    long long n,tc,t=1,xl,yl,xr,yr,x1,x2,y1,y2,i;
    bool f;
    scanf("%lld",&tc);
    while(tc--)
    {

        scanf("%lld",&n);
        scanf("%lld %lld %lld %lld",&xl,&yl,&xr,&yr);
        f=false;
        for(i=1;i<n;i++)
        {

            scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
            //printf("%d %d %d %d",x1-xr,y1-yr,xl-x2,yl-y2);
            if(x1>=x2 || y1>=y2 || x1>=xr || y1>=yr || x2<=xl || y2<=yl)
            {
                f=true;
            }
            if(!f)
            {
                xl=max(x1,xl);
                yl=max(y1,yl);
                xr=min(x2,xr);
                yr=min(y2,yr);
            }
        }
        if(f)
        printf("Case %lld: 0\n",t++);
        else
        printf("Case %lld: %lld\n",t++,abs(xr-xl)*abs(yr-yl));
    }
    return 0;
}
