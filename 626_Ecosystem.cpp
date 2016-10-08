//Problem Type :
//Time :    0.064
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
int x[5],g[110][110],n;
bool v[110];
vector<vector<int> > cycle;
bool sorted(vector<int> t)
{
    if((t[0]> t[1] && t[1]>t[2]) || (t[0]< t[1] && t[1]<t[2]) )
    return true;
    return false;
}
void echosystem(int s,int k,int u)
{
    x[k]=u;
    if(k==3 && g[u][s])
    {
        vector<int> t(x+1,x+4);
        while(!sorted(t))
        rotate(t.begin(),t.begin()+1,t.end());
        cycle.push_back(t);
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(g[u][i] && !v[i])
            {
                v[i]=true;
                echosystem(s,k+1,i);
                v[i]=false;
            }
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&g[i][j]);
        }
        memset(v,false,sizeof(v));
        for(i=1;i<=n;i++)
        {
            v[i]=true;
            echosystem(i,1,i);
            //v[i]=false;
        }
        sort(cycle.begin(),cycle.end());
        for(i=0;i<cycle.size();i++)
            printf("%d %d %d\n",cycle[i][0],cycle[i][1],cycle[i][2]);
        printf("total:%d\n",cycle.size());
        printf("\n");
        cycle.clear();
    }
    return 0;
}
