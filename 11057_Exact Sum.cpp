#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;

struct res{
int d,a,b;
};

bool comp(res a,res b)
{
    return a.d<b.d;
}
int main()
{
    vector<res> v;
    res r;
    int f[1000020],n,x,i,y,a,b;
    list<int> lst;
    list<int> :: iterator it;
    while(scanf("%d",&n)==1)
    {
        memset(f,0,sizeof(f));
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            f[x]++;
            lst.push_back(x);
        }
        lst.sort();
        lst.unique();

        scanf("%d",&y);

        for(it=lst.begin();it!=lst.end();it++)
        {
            a=*it;
            f[a]--;
            b=y-a;
            if(b>0 && b<1000020)
            if(f[b])
            {
                r.d=abs(a-b);
                if(a<b)
                {
                    r.a=a;
                    r.b=b;
                }
                else
                {
                    r.a=b;
                    r.b=a;
                }
                v.push_back(r);
            }
            f[a]++;
        }
        sort(v.begin(),v.end(),comp);
        printf("Peter should buy books whose prices are %d and %d.\n\n",v[0].a,v[0].b);
        v.clear();
        lst.clear();
    }
    return 0;
}
