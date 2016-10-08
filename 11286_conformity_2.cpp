#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    map<vector<int> , int> mpv;
    map<vector<int> , int> :: iterator it;
    vector<int> v;
    int n,i,j,x,y,mx,c;
    while(scanf("%d",&n) && n)
    {
        int in=1;
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++)
            {
                scanf("%d",&x);
                v.push_back(x);
            }
            sort(v.begin(),v.end());
            mpv[v]++;
            v.clear();
        }
        mx=c=0;
        for(it=mpv.begin();it!=mpv.end();it++)
        {
            y=it->second;
            if(mx==y)
            {
                c++;
            }
            if(mx<y)
            {
                mx=y;
                c=0;
            }


        }
        printf("%d\n",mx+c*mx);
        mpv.clear();
    }
    return 0;
}
