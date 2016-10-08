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

int d[210][210][210],A,B,C,D,res[210],INF;


struct jugs
{
    int a,b,c,cost;
    bool operator < (const jugs &p) const
    {
        return cost > p.cost;
    }


};

void fill_bfs()
{
    priority_queue<jugs>pq;
    jugs j;
    int u,v,i,a,b,c,ae,be,ce,na,nb,nc,cost;

    memset(d,63,sizeof(d));
    memset(res,63,sizeof(res));
    INF=d[0][0][0];

    d[0][0][C]=0;
    j.a=0;
    j.b=0;
    j.c=C;
    j.cost=0;
    pq.push(j);

    while(!pq.empty())
    {
        j=pq.top();pq.pop();
        a=j.a;
        b=j.b;
        c=j.c;

        //cout<<a<<" "<<b<<" "<<c<<" "<<d[a][b][c]<<endl;

        res[a]=min(d[a][b][c],res[a]);
        res[b]=min(d[a][b][c],res[b]);
        res[c]=min(d[a][b][c],res[c]);

        ae=A-a;
        be=B-b;
        ce=C-c;

        // a to b
        if(a>=be)
        {
            na=a-be;
            nb=B;
            nc=c;
            cost=be;

            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }
        else
        {
            na=0;
            nb=b+a;
            nc=c;
            cost=a;
            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }

        // a to c
        if(a>=ce)
        {
            na=a-ce;
            nb=b;
            nc=C;
            cost=ce;

            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }
        else
        {
            na=0;
            nb=b;
            nc=c+a;
            cost=a;
            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }

        // b to a
        if(b>=ae)
        {
            na=A;
            nb=b-ae;
            nc=c;
            cost=ae;

            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }
        else
        {
            na=a+b;
            nb=0;
            nc=c;
            cost=b;
            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }

        // b to c
        if(b>=ce)
        {
            na=a;
            nb=b-ce;
            nc=C;
            cost=ce;

            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }
        else
        {
            na=a;
            nb=0;
            nc=c+b;
            cost=b;
            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }

        // c to a
        if(c>=ae)
        {
            na=A;
            nb=b;
            nc=c-ae;
            cost=ae;

            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }
        else
        {
            na=a+c;
            nb=b;
            nc=0;
            cost=c;
            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }

        // c to b
        if(c>=be)
        {
            na=a;
            nb=B;
            nc=c-be;
            cost=be;

            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }
        else
        {
            na=a;
            nb=b+c;
            nc=0;
            cost=c;
            if(d[na][nb][nc]>d[a][b][c]+cost)
            {
                d[na][nb][nc]=d[a][b][c]+cost;
                j.a=na;
                j.b=nb;
                j.c=nc;
                j.cost=d[na][nb][nc];
                pq.push(j);
            }

        }


    }
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d %d",&A,&B,&C,&D);
        fill_bfs();

        do
        {
            if(res[D]!=INF)
            {
                printf("%d %d\n",res[D],D);
                break;
            }
        }while(D--);


    }
    return 0;
}
