#include<stdio.h>
#include<string.h>

char g[110][110],r,c;



int largest_squre(int x,int y)
{
    char ch=g[x][y];
    int n=1,i,j,x1,x2,y1,y2;
    for(i=1; ; i++)
    {
        x1=x+(-1*i);
        x2=x+(1*i);
        y1=y+(-1*i);
        y2=y+(1*i);

        //up+down
        for(j=y1;j<=y2;j++)
        if(g[x1][j]!=ch)
        if(g[x1][j]!=g[x2][j])
        return n;

        //left+right
        for(j=x1;j<=x2;j++)
        if(g[j][y1]!=ch)
        if(g[j][y1]!=g[j][y2])
        return n;


        n+=2;
    }
}

void precal()
{
    int i,j;
    char ch;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            ch=g[i][j];
            if(check)
        }
    }
}

int main()
{
    int tc,q,i,x,y;
    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d %d %d",&r,&c,&q);
        for(i=1;i<=r;i++)
        scanf("%s",g[i]+1);

        for(i=0;i<=c;i++)
        g[0][i]=g[r+1][i]=' ';
        for(i=0;i<=r;i++)
        g[i][0]=g[i][c+1]=' ';

        printf("%d %d %d\n",r,c,q);
        for(i=0;i<q;i++)
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",largest_squre(x+1,y+1));
        }

    }
    return 0;
}
