//Problem Type :    DFS,backtracking,wandroff's rule
//Time :    .232
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

int D[51][51],n;
bool V[51][51];
int X[]={-1,-2,-2,-1,1,2,2,1};
int Y[]={-2,-1,1,2,2,1,-1,-2};
bool night_path;
struct xy
{
    int m,d,x,y;
    xy(){}

    xy(int m,int d,int x,int y) : m(m), d(d) , x(x) ,y(y)  {}

    bool operator < (const xy &p)
    const
    {
        if(m==p.m)
        {

                return (d>p.d);
        }
        else
            return m<p.m;
    }
};



bool valid(int x,int y)
{
    if(V[x][y] || x<1 || y<1 || x>n || y>n)
    return false;

    return true;
}
int euclidean_distance(int x,int y)
{
    int p=n/2,q=n/2;
    return max(abs(x-p),abs(y-q));
    return (x-p)*(x-p)+(y-q)*(y-q);
}
int onward_moves(int x,int y)
{
    int u,v,c=0,i;
    for(i=0;i<8;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v))
            c++;
    }
    return c;

}

bool BFS(int x,int y)
{
    queue<int>q;
    int i,u,v;
    vector<xy> next;

    D[x][y]=1;
    V[x][y]=true;
    q.push(x);
    q.push(y);
    if(n==1)
        return true;
    if(n%2==1)
        return false;

    while(!q.empty())
    {
        x=q.front();q.pop();
        y=q.front();q.pop();

        next.clear();
        for(i=0;i<8;i++)
        {
            u=x+X[i];
            v=y+Y[i];

            if(valid(u,v))
            {
                next.push_back(xy(onward_moves(u,v),euclidean_distance(u,v),u,v));
            }
        }
        if(next.size())
        {
            sort(next.begin(),next.end());

            //for(i=0;i<next.size();i++)
                //printf("%d %d %d %d\n",next[i].m,next[i].d,next[i].x,next[i].y);
            //printf("\n");

            u=next[0].x;
            v=next[0].y;
            D[u][v]=D[x][y]+1;
            V[u][v]=true;
            q.push(u);
            q.push(v);

            if(D[u][v]==n*n)
                return true;
        }
    }
    return false;
}
void DFS(int x,int y,int k)
{
    int i,u,v,w,j;
    vector<xy> next;


    if(k==n*n)
    {
        //print();
        night_path=true;
        return;
    }

    for(i=0;i<8;i++)
    {
        u=x+X[i];
        v=y+Y[i];

        if(valid(u,v))
            next.push_back(xy(onward_moves(u,v),euclidean_distance(u,v),u,v));
    }
    if(next.size())
    {
        sort(next.begin(),next.end());
        w=next[0].m;
        for(j=0;j<next.size() && next[j].m==w;j++)
        {
            D[next[j].x][next[j].y]=k+1;
            V[next[j].x][next[j].y]=true;

            DFS(next[j].x,next[j].y,k+1);
            if(night_path)
                return;

            D[next[j].x][next[j].y]=0;
            V[next[j].x][next[j].y]=false;

        }
    }


}
void print()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%5d",D[i][j]);
        printf("\n");
    }
}
int main()
{
    int x,y;
    bool f=false;
    /*
    for(n=6;n<=50;n+=2)
        for(x=1;x<=n;x++)
            for(y=1;y<=n;y++)
            */
    while(scanf("%d %d %d",&n,&x,&y)==3)
    {
        if(f)
        printf("\n");
        f=true;

        memset(D,0,sizeof(D));
        memset(V,false,sizeof(V));

        //if(BFS(x,y))
        night_path=false;
        D[x][y]=1;
        V[x][y]=true;
        if(n%2!=1 || n==1)
        DFS(x,y,1);

        if(night_path)
            print();
        else
        {
            printf("No Circuit Tour.\n");
            //cout<<x<<" "<<y<<" "<<n<<endl;
            //return 0;
        }
    }
    return 0;
}
