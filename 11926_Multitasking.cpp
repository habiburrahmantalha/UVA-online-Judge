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

struct task
{
    int start,end;
};
bool cmp(task a,task b)
{
    if(a.start==b.start)
    return a.end<b.end;
    return a.start<b.start;
}
task T[1000010];

bool conflict(int l)
{
    for(int i=0;i<l-1;i++)
    if(T[i].end>T[i+1].start)
    return true;

    return false;
}
int main()
{
    int n,m,i,a,b,c,in;
    while(scanf("%d %d",&n,&m) && n+m)
    {
        for(i=0;i<n;i++)
        scanf("%d %d",&T[i].start,&T[i].end);
        in=i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);

            while(a<=1000000)
            {
                T[in].start=a;
                T[in].end=b;
                a+=c;
                b+=c;
                in++;
            }
        }
        sort(T,T+in,cmp);

        if(!conflict(in))
        printf("NO CONFLICT\n");
        else
        printf("CONFLICT\n");
    }
    return 0;
}
