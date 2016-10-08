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

int g[11][101],m,n,mn;
int x[110];
vector<vector<int> >res;
vector<int> t;
void TSP_path(int i,int j,int sum)
{
    if(sum>mn)
    return;
    if(j==m-1)
    {
        x[j]=i;
        //for(int k=0;k<=j;k++)
        //cout<<x[k]<<" ";
        //cout<<endl;
        if(mn>sum)
        {
            mn=sum;
            res.clear();
            t.clear();
            t.assign(x,x+j+1);
            res.push_back(t);
        }
        else if(mn==sum)
        {
            t.clear();
            t.assign(x,x+j+1);
            res.push_back(t);
        }

    }
    else
    {
        x[j]=i;
        //cout<<i<<" ";
        TSP_path((n+i-1)%n,j+1,sum+g[(n+i-1)%n][j+1]);
        TSP_path(i,j+1,sum+g[i][j+1]);
        TSP_path((i+1)%n,j+1,sum+g[(i+1)%n][j+1]);
    }
}
bool cmp(vector<int> i, vector<int> j)
{
    return i<j;
}
int main()
{
    int i,j;
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&n,&m)==2)
    {
        memset(g,0,sizeof(g));
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&g[i][j]);

        mn=(1<<31)-1;
        for(i=0;i<n;i++)
        TSP_path(i,0,g[i][0]);

        sort(res.begin(),res.end(),cmp);


        for(i=0;i<m-1;i++)
        printf("%d ",res[0][i]+1);
        printf("%d\n",res[0][i]+1);
        printf("%d\n",mn);

        res.clear();
    }
    return 0;
}
