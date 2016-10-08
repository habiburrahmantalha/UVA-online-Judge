#include<map>
#include<string>
#include<string.h>
#include<queue>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

int g[210][210],d[210],n;

void bfs(int s,int e)
{
    int u,v;
    memset(d,-1,sizeof(d));
    queue<int> q;

    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(v=1;v<n;v++)
        {
            if(g[u][v] && d[v]==-1)
            {
                d[v]=d[u]+1;
                q.push(v);
                if(v==e)
                    break;
            }
        }
    }
}

int main()
{
    int tc,i,j,c;
    map<string,int>mp;
    vector<string> v;
    stringstream ss;
    string str,a,b;z
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)printf("\n");
        n=1;
        memset(g,0,sizeof(g));
        while(cin>>str && str!="*")
        {
            if(!mp[str])
                mp[str]=n++;
            v.push_back(str);
            for(i=0;i<n-1;i++)
            {
                if(v[i].size()==str.size())
                {

                    c=0;
                    for(j=0;j<str.size();j++)
                        if(str[j]!=v[i][j])
                        c++;
                    if(c==1)
                        g[mp[v[i]]][mp[str]]=g[mp[str]][mp[v[i]]]=1;

                }
            }

        }
        /*
        for(i=1;i<n;i++)
            for(j=1;j<n;j++)
            printf("%d ",g[i][j]);
            */
        getchar();

        while(getline(cin,str) && str.size()!=0)
        {
            ss<<str;
            ss>>a>>b;
            bfs(mp[a],mp[b]);
            cout<<a<<" "<<b<<" "<<d[mp[b]]<<endl;
            ss.clear();
        }
        f=true;
        v.clear();
        mp.clear();

    }
    return 0;
}
