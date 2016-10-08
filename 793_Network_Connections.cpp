#include<stdio.h>
#include<string.h>

int P[1000];
int R[1000];
int n;
int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];

}
void reset()
{
    int i;
    for(i=0;i<=n;i++)
    {
        P[i]=i;
        R[i]=0;
    }
}
void unionset(int x,int y)
{
    int px=findset(x);
    int py=findset(y);

    if(R[px]>R[py])
        P[py]=px;
    else
    {
        P[px]=py;
        if(R[px]==R[py])
            R[py]=R[px]+1;
    }

    //P[px]=P[py];
}
/*
bool isconnected(int x,int y)
{
    if(findset(x)==findset(y))
        return true;
    else
        return false;
}
*/
int main()
{
    int a,b,s1,s2,tc;
    char ch;
    bool NL=false;
    scanf("%d",&tc);
    while(tc--)
    {
        if(NL)
            printf("\n");
        NL=true;
        scanf("%d",&n);
        getchar();

        reset();
        s1=s2=0;
        while(1)
        {
            ch=getchar();
            if(ch=='\n' || ch==EOF)
                break;
            scanf("%d %d",&a,&b);
            getchar();
            if(ch=='c')
                unionset(a,b);
            else
            {
                if(findset(a)==findset(b))
                    s1++;
                else
                    s2++;
            }
        }
        printf("%d,%d\n",s1,s2);

    }
    return 0;
}
