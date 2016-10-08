#include<stdio.h>
#define FOR(i,x,y) for(i=x;i<y;i++)
int F[10010],E[10010];
int n;
int findfriend(int x)
{
    if(x!=F[x])
        F[x]=findfriend(F[x]);
    return F[x];

}
int findenemies(int x)
{
    if(x==-1)
        return -1;
    else
    {
        E[x]=findenemies(E[x]);
        return E[x];
    }

}
void reset()
{
    int i;
    FOR(i,0,n)
    {
        F[i]=i;
        E[i]=-1;
    }

}
void setfriends(int x,int y)
{
    int fx=findfriend(x);
    int fy=findfriend(y);

    int ex=findenemies(x);
    int ey=findenemies(y);


    if(fx==fy)
    {
        F[fy]=F[fx];
        return ;
    }

    if(ex==ey)
    {
        F[fy]=F[fx];
        return;
    }
    if(fx==ey || ex==fy)
    {
        printf("-1\n");
        return;
    }
    F[fy]=F[fx];
}

void setenemies(int x,int y)
{
    int fx=findfriend(x);
    int fy=findfriend(y);

    if(fx==fy)
    {
        printf("-1\n");
        return ;
    }
    int ex=findenemies(x);
    int ey=findenemies(y);
    if(ex==ey)
    {
        if(ex==-1)
            E[fy]=E[fx];
        else
            printf("-1\n");
        return;
    }
    if(fx==ey || ex==fy)
    {
        E[fy]=E[fx];
        return;
    }
    E[fy]=E[fx];
}

bool isenemies(int x,int y)
{
    int ex=findenemies(x);
    int ey=findenemies(y);
    if(ex==ey)
    {
        if(ex==-1)
            return false;
        else
        return true;
    }
    else
        return false;
}

bool isfriends(int x,int y)
{
    int fx=findfriend(x);
    int fy=findfriend(y);

    if(fx==fy)
        return true;
    else
        return false;
}
int main()
{
    int c,a,b,i;
    while(scanf("%d",&n)==1)
    {

        reset();

        for(;;)
        {
            scanf("%d %d %d",&c,&a,&b);
            if(c==0 && a==0 && b==0)
                break;
            if(c==1)
            setfriends(a,b);
            else if(c==2)
            setenemies(a,b);
            else if(c==3)
                if(isfriends(a,b))
                    printf("1\n");
                else
                    printf("0\n");
            else if(c==4)
                if(isenemies(a,b))
                    printf("1\n");
                else
                    printf("0\n");
        }
    }
    return 0;
}

