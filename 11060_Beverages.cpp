#include<string.h>
#include<map>
#include<queue>
#include<string>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>g[110];
int visit[110],n,in[110];
vector<int>res;



int main()
{
    //freopen("in.txt","r",stdin);
    int i,m,t=1,x;

    char name[110][100],s1[100],s2[100];
    map<string,int >mp;

    string xs;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",name[i]);
            mp[name[i]]=i+1;
        }
        scanf("%d",&m);
        memset(in,0,sizeof(in));
        for(i=0;i<m;i++)
        {
            scanf("%s %s",s1,s2);
            g[mp[s1]].push_back(mp[s2]);

            in[mp[s2]]++;
        }
        //for(i=1;i<=n;i++)
        {
            //cout<<name[i-1]<<" "<<in[i]<<endl;
        }

        memset(visit,0,sizeof(visit));
        queue<int>q;
        int j;

        while(1)
        {

            for(i=1;i<=n;i++)
            {
                if(visit[i]==0 && in[i]==0)
                {
                    res.push_back(i);
                    visit[i]=1;
                    for(j=0;j<g[i].size();j++)
                    {
                        in[g[i][j]]--;
                    }
                    i=0;
                }
            }
            if(res.size()==n)
            break;
        }

        printf("Case #%d: Dilbert should drink beverages in this order:",t++);
        for(i=0;i<res.size();i++)
        printf(" %s",name[res[i]-1]);
        printf(".\n\n");

        for(i=0;i<=n;i++)
        g[i].clear();
        res.clear();
        mp.clear();
    }
    return 0;
}
