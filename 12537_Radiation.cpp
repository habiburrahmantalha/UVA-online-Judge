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
int x[200010],y[200010];
int ax,ay,bx,by,r1,r2;
bool p1(int i)
{
    if(x[i] > ax+r1 || x[i] < ax-r1 || y[i] > ay+r1 || y[i] < ay-r1)
    return false;

    return true;
}

bool p2(int i)
{
    if(x[i] > bx+r2 || x[i] < bx-r2 || y[i] > by+r2 || y[i] < by-r2)
    return false;

    return true;
}

int main()
{
    int n,c1,c2,i,q,t=1;
    bool f1,f2;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);

        scanf("%d %d %d %d %d",&ax,&ay,&bx,&by,&q);
        printf("Case %d:\n",t++);
        while(q--)
        {
            scanf("%d %d",&r1,&r2);
            c1=c2=0;
            for(i=0;i<n;i++)
            {
                f1=f2=false;

                if(p1(i))
                    f1=true;

                if(p2(i))
                    f2=true;


                if(f1 && f2)
                    c1++;
                else if(!f1 && !f2)
                    c2++;

            }
            printf("%d\n",max(c2-c1,0));
        }
    }
    return 0;
}
