#include<stdio.h>
#include<string.h>

int g[10][10],a[10];

void backtrack(int s,int c)
{
    int i;
    a[c]=s;
    if(c==8)
    {
        for(i=0;i<9;i++)
            printf("%d",a[i]);
        printf("\n");
        return;
    }
    for(i=1;i<=5;i++)
    {
        if(g[s][i])
        {


            g[s][i]=g[i][s]=0;
            backtrack(i,c+1);
            g[s][i]=g[i][s]=1;
        }

    }
}

int main()
{
    memset(g,0,sizeof(g));

    g[1][2]=g[1][3]=g[1][5]=1;
    g[2][1]=g[2][3]=g[2][5]=1;
    g[3][1]=g[3][2]=g[3][4]=g[3][5]=1;
    g[4][3]=g[4][5]=1;
    g[5][1]=g[5][2]=g[5][3]=g[5][4]=1;

    backtrack(1,0);

    return 0;
}
