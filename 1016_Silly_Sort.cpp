//Problem Type :
//Time :
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

int a[1010],visit[1010],x[1010];
int m[1010];
int c,mn;
void cycle(int i)
{
    visit[i]=true;
    x[c++]=a[i];
    mn=min(a[i],mn);
    if(!visit[m[a[i]]])
        cycle(m[a[i]]);
}

int main()
{

    int n,i,j,b[1010],sum,t=1,p,q;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(b,b+n);
        memset(m,0,sizeof(m));
        for(i=0;i<n;i++)
        {
            m[b[i]]=i;
        }
        memset(visit,false,sizeof(visit));
        sum=0;
        for(i=0;i<n;i++)
        {
            if(!visit[i])
            {
                if(m[a[i]]==i)
                {
                    visit[i]=true;
                    continue;
                }

                c=0;
                mn=a[i];
                cycle(i);

                for(j=0;j<c;j++)
                    sum+=x[j];
                sum-=mn;

                p=b[0]*(c+1)+mn*2;
                q=mn*(c-1);
                sum+=min(p,q);



            }
        }
        printf("Case %d: %d\n\n",t++,sum);

    }
    return 0;
}
