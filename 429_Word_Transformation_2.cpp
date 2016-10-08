#include<string.h>
#include<queue>
#include<stdio.h>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;

int d[210],n;
vector<int> g[205];

void bfs(int s,int e)
{
    int u,v,i;
    memset(d,-1,sizeof(d));
    queue<int> q;

    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<g[u].size();i++)
        {
            v=g[u][i];
            if(d[v]==-1)
            {
                d[v]=d[u]+1;
                if(v==e)
                    break;
                q.push(v);
            }
        }
    }
}

int main()
{
    int tc,i,j,k,c,len,in,s,e;
    map<string,int> mp;

    char a[12],b[12],x[50],w[205][12];
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)printf("\n");
        n=1;

        while(1)
        {
            scanf("%s",w[n]);
            if(w[n][0]=='*')
                break;
            mp[w[n]]=n++;

        }
        for(i=1;i<n;i++)
        {
            len=strlen(w[i]);
            for(j=i+1;j<n;j++)
            {
                if(strlen(w[j])==len)
                {
                    c=0;
                    for(k=0;k<len;k++)
                        if(w[i][k]!=w[j][k])
                        {
                            c++;
                            if(c>1)
                            break;
                        }

                    if(c==1)
                    {
                            g[i].push_back(j);
                            g[j].push_back(i);
                    }

                }


            }
        }
        /*
        for(i=1;i<n;i++)
            for(j=1;j<n;j++)
            printf("%d ",g[i][j]);
            */
        getchar();

        while(gets(x))
        {
            if(strlen(x)==0)
                break;
            sscanf(x,"%s %s",a,b);

            bfs(mp[a],mp[b]);
            printf("%s %s %d\n",a,b,d[mp[b]]);
        }
        for(i=0;i<205;i++)
        g[i].clear();
        mp.clear();
        f=true;
    }
    return 0;
}
