//Problem Type : graph :?
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

vector<int>gi[2010],gd[2010];
int a[2010],di[2010],dd[2010],n;

void dfsi(int s,int k)
{
    di[s]=k;
    for(int i=0;i<gi[s].size();i++)
        if(di[gi[s][i]]<k)
            dfsi(gi[s][i],k+1);

}
void dfsd(int s,int k)
{
    dd[s]=k;
    for(int i=0;i<gd[s].size();i++)
        if(dd[gd[s][i]]<k)
            dfsd(gd[s][i],k+1);

}

void make_graph_i()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
            if(a[i]>a[j])
                gi[i].push_back(j);
    }
}
void make_graph_d()
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
            if(a[i]>a[j])
                gd[i].push_back(j);
    }
}
int main()
{
    int tc,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);

        make_graph_i();
        make_graph_d();


        memset(di,0,sizeof(di));
        memset(dd,0,sizeof(dd));
        for(i=0;i<n;i++)
        {
            if(di[i]<=0)
                dfsi(i,1);
        }
        for(i=0;i<n;i++)
        {
            if(dd[i]<=0)
                dfsd(i,1);
        }

        int mx=0;
        for(i=0;i<n;i++)
        //cout<<dd[i]<<" "<<di[i]<<endl;
            mx=max(dd[i]+di[i]-1,mx);
        printf("%d\n",mx);

        for(i=0;i<n;i++)
        {
            gd[i].clear();
            gi[i].clear();

        }
    }
    return 0;
}
