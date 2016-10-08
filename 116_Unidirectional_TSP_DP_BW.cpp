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

#define LL long long

LL g[15][105];
int m,n,pi[15][105];
#define F1(i) (n+i-1)%n
#define F2(i) (i+1)%n

struct data
{
    int v,i;
};
void find_path(int i,int j)
{
    //cout<<i<<j;
    if(j==m-1)
    {
        printf("%d\n",i+1);
    }
    else
    {
        printf("%d ",i+1);
        find_path(pi[i][j],j+1);


    }
}
bool cmp(data i, data j)
{
    if(i.v==j.v)
        return i.i<j.i;
    return i.v<j.v;

}
void TSP()
{
    int i,j;
    for(j=m-2;j>=0;j--)
    {

        for(i=0;i<n;i++)
        {
            data x[3];
            //printf("%d %d %d %d\n",i,j,F1(i),F2(i));
            x[0].v=g[i][j]+g[F1(i)][j+1];
            x[0].i=F1(i);

            x[1].v=g[i][j]+g[i][j+1];
            x[1].i=i;

            x[2].v=g[i][j]+g[F2(i)][j+1];
            x[2].i=F2(i);

            sort(x,x+3,cmp);

            g[i][j]=x[0].v;
            pi[i][j]=x[0].i;

        }
    }
}
void print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        printf("%3lld ",g[i][j]);
        printf("\n");
    }
}

int main()
{
    int i,j,row;

    LL mn;
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&n,&m)==2)
    {

        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%lld",&g[i][j]);

        TSP();
        //print();


        mn=g[0][0];
        row=0;
        for(i=0;i<n;i++)
        if(mn>g[i][0])
        {
            mn=g[i][0];
            row=i;
        }
        find_path(row,0);
        printf("%lld\n",mn);

    }
    return 0;
}
