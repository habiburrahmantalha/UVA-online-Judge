#include<stdio.h>
#include<map>
#include<queue>
#include<string.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

bool g[31][31];
int d[31],M;

void bfs(int s,int e)
{
    queue<int> q;

    int u,v;

    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        u=q.front();q.pop();
        for(v=0;v<M;v++)
        {
            if(g[u][v] && d[v]==-1)
            {
                d[v]=d[u]+1;
                if(v==e)
                return;
                q.push(v);
            }
        }
    }
}

int main()
{
    string wh,wh1;
    int tc,tcase=1,N,P,i,request;
    scanf("%d",&tc);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    while(tc--)
    {
        printf("DATA SET  %d\n\n",tcase++);
        memset(g,false,sizeof(g));
        map<string,int> WH;
        scanf("%d %d %d",&M,&N,&P);

        for(i=0;i<M;i++)
        {
            cin>> wh;
            WH[wh]=i;
        }
        for(i=0;i<N;i++)
        {
            cin>>wh>>wh1;
            g[WH[wh]][WH[wh1]]=g[WH[wh1]][WH[wh]]=true;
        }

        for(i=0;i<P;i++)
        {
            memset(d,-1,sizeof(d));
            cin>>request>>wh>>wh1;
            bfs(WH[wh],WH[wh1]);
            if(d[WH[wh1]]==-1)
            printf("NO SHIPMENT POSSIBLE\n");
            else
            printf("$%d\n",d[WH[wh1]]*request*100);
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}
