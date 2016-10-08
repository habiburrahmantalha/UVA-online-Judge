#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int a[21],b[21],n;

int LCS()
{
    int t[21][21],i,j;

    memset(t,0,sizeof(t));

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(a[i]==b[j])
                t[i+1][j+1]=t[i][j]+1;
            else
                t[i+1][j+1]=max(t[i][j+1],t[i+1][j]);
        }
    }
    //for(i=0;i<=n;i++){
        //for(j=0;j<=n;j++)
        //printf("%d ",t[i][j]);
    //printf("\n");}
    return t[n][n];
}
int main()
{
    int x,i,c;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&x);
        a[x-1]=i+1;
    }
    while(scanf("%d",&x)==1)
    {
        b[x-1]=1;
        for(i=1;i<n;i++)
        {
            scanf("%d",&x);
            b[x-1]=i+1;
        }
        c=LCS();
        printf("%d\n",c);
    }
    return 0;

}
