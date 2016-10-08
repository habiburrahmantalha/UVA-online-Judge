#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;


bool comp(int a,int b)
{
    return a > b;
}
int main()
{
    int tc,r,c,m,n,F[26],i,j,sum,t=1;
    char g[100][100];
    scanf("%d",&tc);
    while(tc--)
    {
        memset(F,0,sizeof(F));
        scanf("%d %d %d %d",&r,&c,&m,&n);
        for(i=0;i<r;i++)
        {
            scanf("%s",g[i]);
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                F[g[i][j]-'A']++;
            }
        }
        sort(F,F+26,comp);
        sum=0;
        for(i=0;i<26 && F[i]>0;i++)
        {
            //printf("%c %d\n",i+'A',F[i]);
            if(F[0]==F[i])
                sum+=F[i]*m;
            else
                sum+=F[i]*n;
        }
        printf("Case %d: %d\n",t++,sum);
    }
    return 0;
}
