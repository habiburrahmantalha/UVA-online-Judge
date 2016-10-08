//Problem Type : Union find
//Time :
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

int P[100010],Psize[100010],n,Psum[100010];

vector<int>next[100010];

void initialize()
{

    for(int i=0;i<=n;i++)
    {
        P[i]=Psum[i]=i;
        Psize[i]=1;
        next[i].clear();
    }
}
int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];

}
void unionset(int x,int y)
{
    int px=findset(x);
    int py=findset(y);
    if(px==py)
    return;
    P[py]=P[px];
    Psize[px]+=Psize[py];
    Psum[px]+=Psum[py];

    next[px].push_back(y);
    for(i=0;i<next[py].size();i++)
    next[px].push_back(next[py][i]);

}
void move(int x,int y)
{
    int xx=findset(x);
    int yy=findset(y);
    if(xx==yy)
    return;

    if(xx!=x)
    {
        Psize[xx]--;
        Psum[xx]-=x;
        Psum[x]=x;
        P[x]=x;
        next
    unionset(y,x);

}
int main()
{
    int m,i,op,a,b;
    while(scanf("%d %d",&n,&m)==2)
    {
        initialize();
        for(i=0;i<m;i++)
        {
            scanf("%d",&op);
            switch(op)
            {
                case 1:
                {
                    scanf("%d %d",&a,&b);
                    unionset(a,b);
                    break;
                }
                case 2:
                {
                    scanf("%d %d",&a,&b);
                    move(a,b);
                    break;
                }
                case 3:
                {
                    scanf("%d",&a);
                    printf("%d %d\n",Psize[findset(a)],Psum[findset(a)]);
                    break;
                }

            }

        }
    }
    return 0;
}
