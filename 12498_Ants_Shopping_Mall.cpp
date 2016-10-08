//Problem Type :
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
#define inf 2000
int m,n;
char g[55][55];

int mx_move(int a,int b)
{
    int l,r,i;
    r=inf;
    for(i=b;i<m;i++)
    if(g[a][i]=='0')
    {
        r=(i-b);
        break;
    }
    l=inf;
    for(i=b;i>=0;i--)
    if(g[a][i]=='0')
    {
        l=(b-i);
        break;
    }
    if(l<r)
    r=l;
    return r;
}
int main()
{
    int tc,i,j,mn,t=1,T[55][55],s;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%s",g[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                T[i][j]=mx_move(i,j);
                //cout<<T[i][j]<<" ";
            }
            //cout<<endl;
        }
        mn=inf;
        for(i=0;i<m;i++)
        {
            s=0;
            for(j=0;j<n;j++)
            s+=T[j][i];

            //cout<<s<<" ";

            if(s<mn)
            mn=s;
        }
        if(mn>=inf)
        printf("Case %d: -1\n",t++);
        else
        printf("Case %d: %d\n",t++,mn);

    }
    return 0;
}
