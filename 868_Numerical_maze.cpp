#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


struct M
{
    int s,e;
};

bool comp(M a,M b)
{
    if(a.s==b.s)
        return a.e<b.e;
    else
    return a.s<b.s;
}

vector<M> vm;
M res;
int p[1000];
int g[500][500],n,m;
void path()
{
    int i,j,k=1,l=0;
    for(i=1;i<=100;i++)
    {
        for(j=1;j<k;j++)

        p[l++]=j;
        k++;

    }
    //for(i=0;i<l;i++)
    //printf("%d ",p[i]);

}
int X[]={0,1,0,-1};
int Y[]={-1,0,1,0};
bool valid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
    return false;
    return true;
}
void maze(int x,int y,int k)
{
    int i,u,v;
    if(n-1==x)
    {
        res.e=y+1;
        vm.push_back(res);
        //printf("%d %d",x+1,y+1);
        return;
    }
    for(i=0;i<4;i++)
    {
        u=x+X[i];
        v=y+Y[i];
        if(valid(u,v) && g[u][v]==p[k])
        {
            maze(u,v,k+1);
        }
    }
}
int main()
{
    path();
    int tc,i,j;
    bool f=false;
    scanf("%d",&tc);
    while(tc--)
    {
        if(f)
        printf("\n");
        f=true;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&g[i][j]);

            }
        }
        for(i=0;i<m;i++)
        {
            if(g[0][i]==1)
            {

                res.s=i+1;
                maze(0,i,1);
            }
        }
        sort(vm.begin(),vm.end(),comp);
        printf("1 %d\n%d %d\n",vm[0].s,n,vm[0].e);
        vm.clear();
    }
    return 0;
}
