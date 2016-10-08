#include<stdio.h>
#include<string.h>
int g[11][11],n,x[11],w;
bool f;
bool unvisited(int a,int b)
{
    int i;
    for(i=0;i<a;i++)
        if(b==x[i])
            return false;
    return true;
}
void backtrack(int i,int k)
{
    int j;
    x[i]=k+1;

    if(i==w)
    {
        f=true;
        printf("(");
        for(j=0;j<w;j++)
        printf("%d,",x[j]);
        printf("%d)\n",x[j]);
        return;

    }
    for(j=0;j<n;j++)
        if(g[k][j])
        {

            if(unvisited(i,j+1))
            backtrack(i+1,j);
        }
}
int main()
{
    int i,j,y;
    while(scanf("%d %d",&n,&w)==2)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                scanf("%d",&g[i][j]);
        }
        f=false;
        backtrack(0,0);
        if(!f)
            printf("no walk of length %d\n",w);
        while(scanf("%d",&y)==1 && y==-9999)
        {
            printf("\n");
            break;
        }
    }
    return 0;
}
