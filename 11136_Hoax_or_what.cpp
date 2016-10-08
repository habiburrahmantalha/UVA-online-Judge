#include<stdio.h>
#include<map>

using namespace std;

int main()
{
    long long a,b,x,n,m,k,i,j,sum;
    map<long long,int> mp;
    map<long long,int> :: iterator it;
    while(scanf("%lld",&n) && n)
    {

        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&m);
            for(j=0;j<m;j++)
            {
                scanf("%lld",&x);
                mp[x]++;

            }
            it=mp.end();
            it--;
            a=it->first;
            mp[a]--;
            if(mp[a]==0)
                mp.erase(a);

            it=mp.begin();
            b=it->first;
            mp[b]--;
            if(mp[b]==0)
                mp.erase(b);
                /*
            for(it=mp.end();;it--)
            {
                if(it->second>0)
                {
                    a=it->first;
                    mp[a]--;
                    //printf("%d ",a);
                    break;
                }
            }
            for(it=mp.begin();;it++)
            {
                if(it->second>0)
                {
                    b=it->first;
                    mp[b]--;
                    //printf("%d\n",b);
                    break;
                }
            }
            */
            sum+=a-b;
        }
        printf("%lld\n",sum);
        mp.clear();

    }
    return 0;
}
