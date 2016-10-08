#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iterator>
#include<vector>
#define LL long long
using namespace std;

struct xy
{
    LL x;
    double y;
};
bool comp(xy a,xy b)
{
    if(a.y==b.y)
    return a.x<b.x;
    return a.y<b.y;
}
int main()
{

    LL n,k,d,x;
    double sum;
    int tc,t,i;
    xy cakes[1010],drinks[1010];
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {

        scanf("%lld %lld %lld",&n,&k,&d);
        sum=0;
        for(i=0;i<k;i++)
        {
            scanf("%lld",&x);
            sum+=x;

                cakes[i].x=x;
        }
        for(i=0;i<d;i++)
        {
            scanf("%lld",&x);
            sum+=x;

                drinks[i].x=x;
        }
        for(i=0;i<n-d-k;i++)
        {
            scanf("%lld",&x);
            sum+=x;
        }



        sum=sum/n;
        for(i=0;i<k;i++)
        {
            cakes[i].y=fabs(sum-cakes[i].x);
        }
        for(i=0;i<d;i++)
        {
            drinks[i].y=fabs(sum-drinks[i].x);
        }
        sort(cakes,cakes+k,comp);
        sort(drinks,drinks+d,comp);

        printf("Case #%d: %lld %lld\n",t,cakes[0].x,drinks[0].x);

    }
    return 0;

}
