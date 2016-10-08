#include<stdio.h>
#include<queue>
#include<string.h>
#include<string>
#include<map>
#include<iostream>

using namespace std;
int N;
bool g[1001][1001];
int pi[1001],visit[1001];
map<int,string> city1;
void bfs(int s,int e)
{
    queue<int> q;
    int u,v;
    memset(visit,0,sizeof(visit));
    pi[s]=s;
    q.push(s);
    visit[s]=1;
    while(!q.empty())
    {
        u=q.front();q.pop();
        //printf("%d\n",u);
        for(v=1;v<N;v++)
        {

            if(g[u][v] && visit[v]==0)
            {
                //printf("%d\n",g[u][v]);

                visit[v]=1;
                pi[v]=u;
                q.push(v);
                //if(v==e)
                //return;
            }
        }
    }
}
int start;
void print_path(int s,int e)
{
    if(start==s){
        cout<<city1[s]<<" "<<city1[e]<<endl;
        return;
    }
    else {
        print_path(pi[s],s);
        //cout<<" "<<city1[s]<<endl;
        cout<<city1[s]<<" "<<city1[e]<<endl;
    }
}

int main()
{
    int n,i;
    string a,b;
    bool f=false;
    while(scanf("%d",&n)==1)
    {
        if(f)
        printf("\n");
        memset(g,false,sizeof(g));
        map<string,int> city;
        city1.clear();
        N=1;
        for(i=0;i<n;i++)
        {
            cin>>a>>b;
            if(!city[a]) {
                city[a]=N++;
                city1[N-1]=a;
            }

            if(!city[b]) {
                city[b]=N++;
                city1[N-1]=b;
            }
            g[city[a]][city[b]]=g[city[b]][city[a]]=true;
            //printf("%d\n", g[city[a]][city[b]]);

        }
        cin>>a>>b;
        if(city[a]==0 || city[b]==0)
        {
            printf("No route\n");
            f=true;
            continue;
        }
        bfs(city[a],city[b]);
        if(visit[city[b]]) {
            start=city[a];
            print_path(pi[city[b]],city[b]);
        }
        else
        printf("No route\n");
        f=true;
    }
    return 0;
}
