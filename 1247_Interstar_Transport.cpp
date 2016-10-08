#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
#define inf 20000000
int g[30][30],n,p[30][30];

void warshal()
{
    int i,j,k;

    for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(g[i][j]>g[i][k]+g[k][j])
    {
        g[i][j]=g[i][k]+g[k][j];
        p[i][j]=p[k][j];
    }
}
void reset()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            g[i][j]=inf;
            p[i][j]=i;
        }
        g[i][i]=0;
    }

}
void print_path(int a,int b)
{
    if(a==b)
    {
        printf("%c",a+'A');
        return;
    }
    else
    {
        print_path(a,p[a][b]);
        printf(" %c",b+'A');
    }
}
int main()
{
    int m,i,c,q;
    char a[5],b[5];
    while(scanf("%d %d",&n,&m)==2)
    {
        reset();
        for(i=0;i<m;i++)
        {
            scanf("%s %s %d",a,b,&c);
            g[a[0]-'A'][b[0]-'A']=g[b[0]-'A'][a[0]-'A']=c;
        }
        warshal();
        scanf("%d",&q);
        for(i=0;i<q;i++)
        {
            scanf("%s %s",a,b);
            print_path(a[0]-'A',b[0]-'A');
            printf("\n");
        }
    }
    return 0;
}
