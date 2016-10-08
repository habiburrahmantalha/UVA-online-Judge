#include<stdio.h>
#include<string.h>

int main()
{
    int xl1,xu1,yl1,yu1,xl2,xu2,yl2,yu2,xl,xu,yl,yu;
    int i,j,tc,g[1000][1000];
    bool f;
    scanf("%d",&tc);

    while(tc--)
    {
        memset(g,0,sizeof(g));

        scanf("%d %d %d %d",&xl1,&yl1,&xu1,&yu1);
        scanf("%d %d %d %d",&xl2,&yl2,&xu2,&yu2);

        for(i=yl1;i<=yu1;i++)
            for(j=xl1;j<=xu1;j++)
                g[i][j]=1;

        for(i=yl2;i<=yu2;i++)
            for(j=xl2;j<=xu2;j++)
                g[i][j]+=1;

        xl=yl=xu=yu=0;
        f=false;

        for(i=0;i<=999;i++)
            for(j=0;j<=999;j++)
            {
                if(f==false && g[i][j]==2)
                {
                    f=true;
                    xl=j;yl=i;
                }
                if(g[i][j]==2)
                {
                    xu=j;
                    yu=i;
                }
            }
        if(!xl && !yl && !xu && !yu)
            printf("No Overlap\n");
        else
            printf("%d %d %d %d\n",xl,yl,xu,yu);

    }
    return 0;
}
