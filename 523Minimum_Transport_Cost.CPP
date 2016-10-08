//something wrong :(
#include<stdio.h>
#include<string.h>
int g[101][101],N,p[101][101],tax[101];

void warshal()
{
    int i,j,k;
    for(k=1;k<=N;k++) {
        for(i=1;i<=N;i++){
            //if(g[i][k]>0)
            for(j=1;j<=N;j++){
                //if(g[i][j]>0 && g[k][j]>0)
                if(g[i][j]<g[i][k]+g[k][j])
                {
                    g[i][j]=g[i][k]+g[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
}
void print_path(int a,int b)
{
    if(a==b)
    {
        printf("%d",a);
        return;
    }
    else
    {
        print_path(a,p[a][b]);
        printf("-->%d",b);
    }
}
int main()
{
    char ch;
    int i,j,tc,a,b;
    scanf("%d",&tc);

    while(tc--)
    {
        for(i=1; ;i++)
        {
            scanf("%d%ch",&g[1][i],&ch);
            if(ch=='\n')
            break;
        }
        N=i;
        for(i=2;i<=N;i++)
        {
            for(j=1;j<=N;j++)
            {
                scanf("%d",&g[i][j]);
            }
        }
        warshal();
        for(i=1;i<=N;i++){
        for(j=1;j<=N;j++)
        printf("%d ",g[i][j]);
        printf("\n");
        }

        for(i=1;i<=N;i++)
        {
            scanf("%d",&tax[i]);
        }
        while(scanf("%d %d",&a,&b))
        {

            printf("From %d to %d :\n",a,b);
            printf("Path: ");
            //print_path(a,b);
            printf("Total cost : %d\n",g[a][b]);
        }
    }
    return 0;
}
