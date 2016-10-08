#include<stdio.h>
#include<string.h>
#include<algorithm>
#define LL long long
#define N 10010
#include<map>

using namespace std;
int main()
{
    map<LL,LL>a,b;
    map<LL,LL> :: iterator it;
    LL tc,i,n,m,mx,res,x;
    scanf("%lld",&tc);
    while(tc--)
    {

        res=0;
        scanf("%lld %lld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);
            a[x]++;

        }
        for(i=0;i<m;i++)
        {
            scanf("%lld",&x);
            a[x]--;

        }

        for(it=a.begin();it!=a.end();it++)
        {
            res+=abs(it->second);
        }
        printf("%lld\n",res);
        a.clear();
    }
    return 0;
}
