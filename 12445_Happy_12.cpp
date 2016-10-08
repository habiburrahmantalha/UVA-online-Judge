//Problem Type : bfs ??
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

int a[]={1,2,3,4,5,6,7,8,9,10,11,12};
vector<int> s(a,a+sizeof(a)/ sizeof(int));
map<vector<int>,int> d,visit;
map<vector<int>,vector<int> > pi;

void print(vector<int> v)
{
    for(int i=0;i<12;i++)
    cout<<v[i]<<" ";
    cout<<endl;
}
void bfs()
{
    queue<vector<int> >q;
    vector<int> u,v;
    int temp;

    q.push(s);
    d[s]=0;
    pi[s]=s;
    visit[s]=1;


    while(!q.empty())
    {
        u=q.front();q.pop();

        //left clockwise
        v=u;
        temp=v[11];
        v[11]=v[0];
        v[0]=v[1];
        v[1]=v[2];
        v[2]=v[3];
        v[3]=v[4];
        v[4]=v[5];
        v[5]=temp;
        if(visit[v]==0 && d[u]+1<20)
        {
            d[v]=d[u]+1;
            pi[v]=u;
            visit[v]=1;
            q.push(v);

            //cout<<"LC :";print(v);
        }

        //left counter clockwise
        v=u;
        temp=v[11];
        v[11]=v[5];
        v[5]=v[4];
        v[4]=v[3];
        v[3]=v[2];
        v[2]=v[1];
        v[1]=v[0];
        v[0]=temp;
        if(visit[v]==0 && d[u]+1<20)
        {
            d[v]=d[u]+1;
            pi[v]=u;
            visit[v]=1;
            q.push(v);

            //cout<<"LCC :";print(v);
        }
        //right clockwise
        v=u;
        temp=v[11];
        v[11]=v[5];
        v[5]=v[6];
        v[6]=v[7];
        v[7]=v[8];
        v[8]=v[9];
        v[9]=v[10];
        v[10]=temp;
        if(visit[v]==0 && d[u]+1<20)
        {
            d[v]=d[u]+1;
            pi[v]=u;
            visit[v]=1;
            q.push(v);

            //cout<<"RC :";print(v);
        }

        //right counter clockwise
        v=u;
        temp=v[11];
        v[11]=v[10];
        v[10]=v[9];
        v[9]=v[8];
        v[8]=v[7];
        v[7]=v[6];
        v[6]=v[5];
        v[5]=temp;
        if(visit[v]==0 && d[u]+1<20)
        {
            d[v]=d[u]+1;
            pi[v]=u;
            visit[v]=1;
            q.push(v);

            //cout<<"RCC :";print(v);
        }

        //ring clockwise
        v=u;
        temp=v[0];
        v[0]=v[2];
        v[2]=v[4];
        v[4]=v[6];
        v[6]=v[7];
        v[7]=v[8];
        v[8]=v[9];
        v[9]=v[10];
        v[10]=v[11];
        v[11]=v[1];
        v[1]=v[3];
        v[3]=v[5];
        v[5]=temp;
        if(visit[v]==0 && d[u]+1<20)
        {
            d[v]=d[u]+1;
            pi[v]=u;
            visit[v]=1;
            q.push(v);

            //cout<<"WC :";print(v);
        }

        //ring counter clockwise
        v=u;
        temp=v[10];
        v[10]=v[9];
        v[9]=v[8];
        v[8]=v[7];
        v[7]=v[6];
        v[6]=v[4];
        v[4]=v[2];
        v[2]=v[0];
        v[0]=v[5];
        v[5]=v[3];
        v[3]=v[1];
        v[1]=v[11];
        v[11]=temp;

        if(visit[v]==0 && d[u]+1<20)
        {
            d[v]=d[u]+1;
            pi[v]=u;
            visit[v]=1;
            q.push(v);

            //cout<<"WCC :";print(v);
        }
        //cout<<" :";print(v);
    }
}
void print_path(vector<int> x)
{
    if(x==s)
    {
        cout<<d[x]<<" :";
        print(x);
        return;
    }
    else
    {
        cout<<d[x]<<" :";
        print(x);
        print_path(pi[x]);

    }
}
int main()
{
    int tc,i,x;
    vector<int> v;
    bfs();
    cout<<d.size();
    scanf("%d",&tc);
    while(tc--)
    {
        v.clear();
        for(i=0;i<12;i++)
        {
            scanf("%d",&x);
            v.push_back(x);
        }

        cout<<d[v]<<endl;
        print_path(v);

    }
    return 0;
}
