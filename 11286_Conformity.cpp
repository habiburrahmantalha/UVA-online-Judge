#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main()
{
    map<vector<int> , int> mpv;
    map<vector<int> , int> :: iterator it;
    vector<int> v;
    int n,i,j,x;
    while(scanf("%d",&n) && n)
    {
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
        int mx=0;
        for(it=mpv.begin();it!=mpv.end();it++)
        {
            if(mx<it->second)
            mx=it->second;
        }
        int c=0;
        for(it=mpv.begin();it!=mpv.end();it++)
        {
            if(mx==it->second)
            c+=mx;
        }
        printf("%d\n",c);
        mpv.clear();
    }
    return 0;
}
