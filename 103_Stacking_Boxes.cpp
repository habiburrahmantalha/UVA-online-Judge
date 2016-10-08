#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int n,d;
int g[35][35],visit[35];
vector<vector<int> > box;
map<vector<int>,int>mp;
int ts[35],mx,res[35],dis[35];


void stacking_box(int i,int j)
{
    //printf("%d ",i);
    if(dis[i]>j)
    return;
    dis[i]=j;
    bool f=false;
    ts[j]=i;
    for(int k=1;k<=n;k++)
    {
        if(g[i][k] && visit[k]==0)
        {
            f=true;
            visit[k]=1;
            stacking_box(k,j+1);
            visit[k]=0;
        }
    }
    if(!f)
    {
        if(j>mx)
        {
            mx=j;
            for(int k=0;k<=mx;k++)
            res[k]=ts[k];
        }
    }
}
bool nested(int i,int j)
{
    int k;
    for(k=0;k<d;k++)
    if(box[i][k]>=box[j][k])
    return false;

    return true;
}
void creat_graph()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        if(i!=j && nested(i,j))
        g[mp[box[i]]][mp[box[j]]]=1;
    }
}

int main()
{
    int k,i,j,x;

    vector<int>v;
    while(scanf("%d %d",&n,&d)==2)
    {
        for(i=0;i<n;i++)
        {
            v.clear();
            for(j=0;j<d;j++)
            {
                scanf("%d",&x);
                v.push_back(x);
            }
            sort(v.begin(),v.end());
            mp[v]=i+1;
            box.push_back(v);
        }
        sort(box.begin(),box.end());
        /*
        for(i=0;i<n;i++)
        {
            for(j=0;j<k;j++)
            printf("%d ",box[i][j]);
            printf("\n");
        }
        */

        memset(g,0,sizeof(g));
        creat_graph();

        /*
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            printf("%d ",g[i][j]);
            printf("\n");
        }
        //*/
        mx=-1;

        for(i=1;i<=n;i++)
        {
            memset(visit,0,sizeof(visit));
            memset(dis,0,sizeof(dis));
            //top_sort(i);
            stacking_box(i,0);
        }
        //printf("-------------\n");
        printf("%d\n",mx+1);
        printf("%d",res[0]);
        for(i=1;i<=mx;i++)
        printf(" %d",res[i]);
        printf("\n");
        //printf("--------------\n");

        box.clear();
        mp.clear();
    }
    return 0;
}
