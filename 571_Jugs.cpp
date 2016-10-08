//BFS 571 Jugs
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

int d[1010][1010],A,B,N;
string W[]={"fill A","fill B","empty A","empty B","pour A B","pour B A"};
struct jugs
{
    int a,b,cost;

    bool operator <(const jugs &p) const
    {
        return cost < p.cost;
    }
};

jugs pi[1010][1010];
int work[1010][1010];


void print_path(int a,int b)
{
    if(d[a][b]!=0)
    {
        //cout<<a<<" "<<b<<endl;
        print_path(pi[a][b].a,pi[a][b].b);
        printf("%s\n",W[work[a][b]-1].c_str());
    }
}

void bfs()
{
    priority_queue<jugs>pq;
    jugs i,j,mnj;
    int a,b,ae,be,aa,bb,c,mn;
    memset(d,63,sizeof(d));

    mn=d[0][0];
    j.a=0;
    j.b=0;
    j.cost=0;

    pq.push(j);
    d[0][0]=0;

    while(!pq.empty())
    {
        i=pq.top();pq.pop();
        a=i.a;
        ae=A-a;
        b=i.b;
        be=B-b;
        c=i.cost+1;

        if(b==N)
        {
            if(mn>d[a][b])
            {
                mnj.a=a;
                mnj.b=b;
                mn=d[a][b];
            }
        }
        //fill A
        aa=A;
        bb=b;
        if(d[aa][bb]>c)
        {
            d[aa][bb]=j.cost=c;
            j.a=aa;
            j.b=bb;
            work[aa][bb]=1;
            pq.push(j);
            pi[aa][bb]=i;

        }

        //fill B
        aa=a;
        bb=B;
        if(d[aa][bb]>c)
        {
            d[aa][bb]=j.cost=c;
            j.a=aa;
            j.b=bb;
            work[aa][bb]=2;
            pq.push(j);
            pi[aa][bb]=i;

        }

        //empty A
        aa=0;
        bb=b;
        if(d[aa][bb]>c)
        {
            d[aa][bb]=j.cost=c;
            j.a=aa;
            j.b=bb;
            work[aa][bb]=3;
            pq.push(j);
            pi[aa][bb]=i;

        }

        //empty B
        aa=a;
        bb=0;
        if(d[aa][bb]>c)
        {
            d[aa][bb]=j.cost=c;
            j.a=aa;
            j.b=bb;
            work[aa][bb]=4;
            pq.push(j);
            pi[aa][bb]=i;

        }

        //pour A->B
        if(a>=be)
        {
            aa=a-be;
            bb=B;
        }
        else
        {
            aa=0;
            bb=b+a;
        }
        if(d[aa][bb]>c)
        {
            d[aa][bb]=j.cost=c;
            j.a=aa;
            j.b=bb;
            work[aa][bb]=5;
            pq.push(j);
            pi[aa][bb]=i;

        }

        //pour B->A
        if(b>=ae)
        {
            aa=A;
            bb=b-ae;
        }
        else
        {
            aa=a+b;
            bb=0;
        }
        if(d[aa][bb]>c)
        {
            d[aa][bb]=j.cost=c;
            j.a=aa;
            j.b=bb;
            work[aa][bb]=6;
            pq.push(j);
            pi[aa][bb]=i;

        }
    }
    print_path(mnj.a,mnj.b);
    printf("success\n");
}


int main()
{
    while(scanf("%d %d %d",&A,&B,&N)==3)
    {
        bfs();
    }
    return 0;
}
