#include<stdio.h>
#include<string.h>

using namespace std;

int X[]={-1,0,1,0};
int Y[]={0,1,0,-1};
char d[]={"NESW"};
char g[100][100];

void traverse(int x,int y)
{
    int i,in=0;
    char s[100000];
    gets(s);
    while(gets(s))
    {
        if(strlen(s)==0)
            break;
        for(i=0;i<strlen(s);i++)
        {
            if(s[i]=='Q')
            {
                printf("%d %d %c\n",x+1,y+1,d[in]);
                return;
            }
            else if(s[i]=='F')
            {
                if(g[x+X[in]][y+Y[in]]==' ')
                {
                    x=x+X[in];
                    y=y+Y[in];
                }

            }
            else if(s[i]=='R')
            {
                in=(in+1)%4;


            }
            else if(s[i]=='L')
            {
                in=in-1;
                if(in<0)
                    in=3;
            }
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    int tc,n,m,i,x,y;
    bool f=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(f)
            printf("\n");
        scanf("%d %d",&n,&m);
        gets(g[0]);
        for(i=0;i<n;i++)
        {
            gets(g[i]);
        }
        scanf("%d %d",&x,&y);
        traverse(x-1,y-1);
        f=true;
    }
}
