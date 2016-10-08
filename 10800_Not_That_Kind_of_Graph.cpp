#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;

int x,y;

void position(char last,char now)
{
    //printf("%c %c\n",last,now);
    if(last=='R')
    {
        if(now=='C')
        x--;
        if(now=='R')
        x--;

    }
    else
    {
        if(now=='F')
        x++;
    }
}
char symbol(char ch)
{
    if(ch=='R')
        return'/';
    else if(ch=='C')
        return '_';
    else
        return '\\';
}
int main()
{
    //freopen("out.txt","w",stdout);
    int tc,i,j,t=1;
    char g[110][110],str[110],last;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",str);
        memset(g,' ',sizeof(g));
        for(i=0;i<=105;i++)
        g[i][0]='|';


        x=50,y=2;
        g[x][y]=symbol(str[0]);
        last=str[0];
        int x1=50,x2=50;
        for(i=1;str[i]!=0;i++)
        {

            y++;
            position(last,str[i]);
            //printf("%d %d\n",x,y);
            g[x][y]=symbol(str[i]);
            last=str[i];
            if(x1<x)
            x1=x;
            if(x2>x)
            x2=x;
        }

        int z=strlen(str)+2;
        printf("Case #%d:\n",t++);
        for(i=x2;i<=x1;i++)
        {
            for(j=z;j>=0;j--)
            if(g[i][j]!=' ')
            break;
            y=j;
            for(j=0;j<=y;j++)
            printf("%c",g[i][j]);
            printf("\n");
        }

        printf("+");
        for(j=1;j<=z;j++)
            printf("-");
        printf("\n");
        printf("\n");
    }
    return 0;
}
