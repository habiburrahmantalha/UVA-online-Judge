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

int d[10001],visit[10001];
map<string,int> mp;
string rule[15][2];
int n,x;
string start,end;
void bfs()
{
    queue<string> q;
    string u,v,T;
    int i,j,k,a,b;

    memset(visit,0,sizeof(visit));
    memset(d,0,sizeof(d));
    x=0;
    mp[start]=x++;
    q.push(start);
    d[mp[start]]=0;
    visit[mp[start]]=1;

    while(!q.empty())
    {
        u=q.front();q.pop();
        a=mp[u];
        for(i=0;i<n;i++)
        {
            v=u;
            for(j=0;j<v.size();j++)
            {
                for(k=1;k<v.size()-j+1;k++)
                {
                    T=v.substr(j,k);
                    if(T.size()>rule[i][0].size())
                    break;

                    if(rule[i][0]==T)
                    {
                        v.replace(j,T.size(),rule[i][1]);
                        //cout<<v<<endl;
                        j=j+T.size();
                        break;
                    }
                }
            }
            if(mp[v]==0)
            mp[v]=x++;
            b=mp[v];
            if(visit[b]==0 && v.size()<=10)
            {
                //cout<<v<<endl;
                d[b]=d[a]+1;
                visit[b]=1;
                q.push(v);
                if(v==end)
                return;

            }
        }
    }
}

int main()
{
    int i;
    string a,b;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            cin>>rule[i][0]>>rule[i][1];
        }
        cin>>start>>end;

        bfs();
        if(mp[end]==0)
        printf("-1\n");
        else
        printf("%d\n",d[mp[end]]);

        mp.clear();
    }
    return 0;
}
