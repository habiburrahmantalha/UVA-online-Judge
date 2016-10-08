#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int N,B,x[100],f[100],i,j;
    while(scanf("%d %d",&N,&B))
    {
        if(N==0 && B==0)
            break;
        for(i=0;i<B;i++)
        {
            scanf("%d",&x[i]);
        }
        memset(f,0,sizeof(f));
        for(i=0;i<B;i++)
            for(j=0;j<B;j++)
            f[abs(x[i]-x[j])]=1;
        bool res=true;
        for(i=0;i<=N;i++)
            if(f[i]==0)
            {
                res=false;
                printf("N\n");
                break;
            }
        if(res)
            printf("Y\n");
    }
}
