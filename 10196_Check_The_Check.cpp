#include<stdio.h>
#include<string.h>

char board[10][10];

bool isvalid(int x,int y)
{
    if(x<0 || x>=8 || y<0 || y>=8)
        return false;
    return true;
}
bool check_pown(int x,int y,int ch)
{
    char pown;
    int s,e,i,a,b;
    if(ch=='k')
    {
        pown='P';
        s=0;
        e=2;
    }
    else
    {
        pown='p';
        s=2;
        e=4;
    }
    int X[]={1,1,-1,-1};
    int Y[]={-1,1,-1,1};
    for(i=s;i<e;i++)
    {
        a=x+X[i];
        b=y+Y[i];
        if(isvalid(a,b) && board[a][b]==pown)
            return true;
    }

    return false;
}

bool check_rock(int x,int y,char ch)
{
    char rock,queen;
    if(ch=='k')
    {
        rock='R';
        queen='Q';
    }
    else
    {
        rock='r';
        queen='q';
    }
    int X[]={0,1,0,-1};
    int Y[]={1,0,-1,0};
    int a,b,i;

    for(i=0;i<4;i++)
    {
        a=x+X[i];
        b=y+Y[i];

        while(isvalid(a,b) && board[a][b]=='.')
        {
            a+=X[i];
            b+=Y[i];
        }
        if(board[a][b]==rock || board[a][b]==queen)
            return true;
    }

    return false;

}

bool check_bishop(int x,int y,char ch)
{
    char bishop,queen;
    if(ch=='k')
    {
        bishop='B';
        queen='Q';
    }
    else
    {
        bishop='b';
        queen='q';
    }
    int X[]={1,1,-1,-1};
    int Y[]={1,-1,-1,1};
    int a,b,i;

    for(i=0;i<4;i++)
    {
        a=x+X[i];
        b=y+Y[i];
        while(isvalid(a,b) && board[a][b]=='.')
        {
            a+=X[i];
            b+=Y[i];
        }
        if(board[a][b]==bishop || board[a][b]==queen)
            return true;
    }
    return false;

}
bool check_knight(int x,int y,char ch)
{
    char knight;
    if(ch=='k')
    knight='N';
    else
    knight='n';

    int X[]={1,2,2,1,-1,-2,-2,-1};
    int Y[]={2,1,-1,-2,-2,-1,1,2};
    int a,b,i;
    for(i=0;i<8;i++)
    {
        a=x+X[i];
        b=y+Y[i];
        if(isvalid(a,b) && board[a][b]==knight)
            return true;
    }
    return false;
}
bool isempty()
{
    int i,j;
    for(i=0;i<8;i++)
        for(j=0;j<8;j++)
            if(board[i][j]!='.')
                return false;
    return true;
}
bool check_black_king(int x,int y)
{
    if(check_pown(x,y,'k') || check_rock(x,y,'k') || check_bishop(x,y,'k') || check_knight(x,y,'k'))
        return true;
    return false;
}

bool check_white_king(int x,int y)
{
    if(check_pown(x,y,'K') || check_rock(x,y,'K') || check_bishop(x,y,'K') || check_knight(x,y,'K'))
        return true;
    return false;
}
int main()
{
    int i,j,kx,ky,Kx,Ky,t=1;
    while(1)
    {
        for(i=0;i<8;i++)
            scanf("%s",board[i]);
        if(isempty())
        break;
        for(i=0;i<8;i++)
            for(j=0;j<8;j++)
            {
                if(board[i][j]=='K')
                {
                    Kx=i;
                    Ky=j;
                }
                if(board[i][j]=='k')
                {
                    kx=i;
                    ky=j;
                }
            }
        if(check_black_king(kx,ky))
            printf("Game #%d: black king is in check.\n",t++);
        else if(check_white_king(Kx,Ky))
            printf("Game #%d: white king is in check.\n",t++);
        else
            printf("Game #%d: no king is in check.\n",t++);
    }
    return 0;
}
