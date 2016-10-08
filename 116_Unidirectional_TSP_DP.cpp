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
vector<vector<int> >res;
vector<int> t;

void find_path(int i,int j)
{
    if(j==0)
    {
        t.push_back(i+1);
    }
    else
    {
        find_path(pi[i][j],j-1);
        t.push_back(i+1);
    }
}

int MIN(int a,int b,int j)
{
    vector<int>u,v;
    int k;
    t.clear();
    find_path(a,j-1);
    t.push_back(a);
    u=t;

    t.clear();
    find_path(b,j-1);
    t.push_back(b);
    v=t;

    if(u>v)
    return b;
    else
    return a;
}
bool cmp(vector<int> i, vector<int> j)
{
    return i<j;
}
void TSP()
{
    int i,j;
    for(j=1;j<m;j++)
    {

        for(i=0;i<n;i++)
        {
            if(g[i][j]+g[(n+i-1)%n][j-1]>g[i][j]+g[i][j-1])
            {
                if(g[i][j]+g[(i+1)%n][j-1]>g[i][j]+g[i][j-1])
                {
                    g[i][j]+=g[i][j-1];
                    pi[i][j]=i;
                }
                else if(g[i][j]+g[(i+1)%n][j-1]==g[i][j]+g[i][j-1])
                {
                    g[i][j]+=g[(i+1)%n][j-1];
                    pi[i][j]=MIN(i,(i+1)%n,j);
                }
                else
                {
                    g[i][j]+=g[(i+1)%n][j-1];
                    pi[i][j]=(i+1)%n;
                }

            }
            else if(g[i][j]+g[(n+i-1)%n][j-1]==g[i][j]+g[i][j-1])
            {
                if(g[i][j]+g[(i+1)%n][j-1]>g[i][j]+g[i][j-1])
                {
                    g[i][j]+=g[i][j-1];
                    pi[i][j]=MIN(i,(n+i-1)%n,j);
                }
                else if(g[i][j]+g[(i+1)%n][j-1]==g[i][j]+g[i][j-1])
                {
                    g[i][j]+=g[i][j-1];
                    pi[i][j]=MIN((i+1)%n,MIN(i,(n+i-1)%n,j),j);
                }
                else
                {
                    g[i][j]+=g[(i+1)%n][j-1];
                    pi[i][j]=(i+1)%n;
                }
            }
            else
            {
                if(g[i][j]+g[(n+i-1)%n][j-1]>g[i][j]+g[(i+1)%n][j-1])
                {
                    g[i][j]+=g[(i+1)%n][j-1];
                    pi[i][j]=(i+1)%n;
                }
                else if(g[i][j]+g[(n+i-1)%n][j-1]==g[i][j]+g[(i+1)%n][j-1])
                {
                    g[i][j]+=g[(n+i-1)%n][j-1];
                    pi[i][j]=MIN((n+i-1)%n,(i+1)%n,j);

                }
                else
                {
                    g[i][j]+=g[(n+i-1)%n][j-1];
                    pi[i][j]=(n+i-1)%n;
                }
            }
        }
    }
}
void print()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        printf("%lld ",g[i][j]);
        printf("\n");
    }
}

int main()
{
    int i,j;
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


        mn=g[0][m-1];
        for(i=0;i<n;i++)
        if(mn>g[i][m-1])
        mn=g[i][m-1];

        for(i=0;i<n;i++)
        if(g[i][m-1]==mn)
        {
            t.clear();
            find_path(i,m-1);
            res.push_back(t);
        }

        sort(res.begin(),res.end(),cmp);
        //if(res.size()==0)
        //continue;
        //for(int k=0;k<res.size();k++)
        {
            for(i=0;i<m-1;i++)
            printf("%d ",res[0][i]);
            printf("%d\n",res[0][i]);
        }
        printf("%lld\n",mn);

        res.clear();

    }
    return 0;
}
