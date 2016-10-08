#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)
struct co
{
    double x,y;
};

double dist(co a,co b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y) );
}
co c[1000000];
bool cmp(co a,co b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    int n,i;
    double sum;

    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf",&c[i].x,&c[i].y);
        }
        sum=0;
        for(i=2;i<=n;i++)
        {
            sum+=dist(c[i-1],c[i]);
            //cout<<sum<<endl;
        }
        //sum+=dist(c[1],c[n]);
        printf("%.2lf\n",sum+2);
    }
    return 0;
}
