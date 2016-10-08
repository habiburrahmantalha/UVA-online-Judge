#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
int w[110],c[110];
/*
void knapsack()
{
    //if(m>2000)
    //m+=200;
    int t[n+5][m+205];
    memset(t,0,sizeof(t));
    int i,j,mx=0,money=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m+200;j++)
        {
            if(j-w[i]>=0)
            {
                //if(j>2000)
                {
                    //if(money+c[i]>2000)
                    t[i][j]=max(c[i]+t[i-1][j-w[i]],t[i-1][j]);
                    //else
                    //t[i][j]=t[i-1][j];

                }
                //else
                //t[i][j]=max(c[i]+t[i-1][j-w[i]],t[i-1][j]);
            }
            else
            t[i][j]=t[i-1][j];

            if(mx<t[i][j])
            {
                mx=t[i][j];
                money=j;
            }
        }
    }
    printf("%d\n",t[n][m+200]);
}
*/
void max_fav()
{
    int mx,i,j,t[10210];
    m+=200;

    memset(t,0,sizeof(t));
    t[0]=1;
    for(i=1;i<=n;i++)
    for(j=m-w[i];j>=0;j--)
    {
        if(t[j])
        {
            t[j+w[i]]=max(t[j+w[i]],t[j]+c[i]);
        }
    }
    mx=0;
    for(i=0;i<=m;i++)
    {
        if(t[i])
        {
            //printf("%d ",t[i]);
            if(m-200<i && i<=2000)
            continue;
            mx=max(mx,t[i]);
        }
    }
    printf("%d\n",mx-1);
}
int main()
{
    int i;
    while(scanf("%d %d",&m,&n)==2)
    {
        for(i=1;i<=n;i++)
        scanf("%d %d",&w[i],&c[i]);
        //knapsack();
        max_fav();
    }
    return 0;
}
