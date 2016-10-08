#include<stdio.h>

long long g[110][110];
int n;

bool is_symmetric()
{
    int i,j,a,b;
    for(i=0,a=n-1;i<n;i++,a--)
    for(j=0,b=n-1;j<n;j++,b--)
    if(g[i][j]<0 || g[i][j]!=g[a][b])
    {
        //printf("%d %d %lld",i,j,g[i][j]);
        return false;
    }

    return true;
}
int main()
{
    int tc,t=1,i,j;
    char s[100];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s %s %d",s,s,&n);
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        scanf("%lld",&g[i][j]);

        if(is_symmetric())
        printf("Test #%d: Symmetric.\n",t++);
        else
        printf("Test #%d: Non-symmetric.\n",t++);
    }
    return 0;
}
