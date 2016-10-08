#include<stdio.h>
#include<string.h>

int P[30];
int n,m;

int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];

}
void reset()
{
    for(int i=0;i<=n;i++)
        P[i]=i;


}
void unionset(int x,int y)
{
    int px=findset(x);
    int py=findset(y);
    P[py]=P[px];
}
int main()
{
    int a,b,i,mx,tc,f[30];
    bool NL=false;
    char ch[10];
    scanf("%d",&tc);
    getchar();
    getchar();
    while(tc--)
    {
        if(NL)
            printf("\n");
        NL=true;
        gets(ch);
        n=ch[0]-'A';
        reset();
        while(gets(ch))
        {
            if(strlen(ch)==0)
                break;
            a=ch[0]-'A';
            b=ch[1]-'A';
            unionset(a,b);
        }

        memset(f,0,sizeof(f));

        for(i=0;i<=n;i++)
        {
            findset(i);
            f[P[i]]++;
        }
        mx=0;
        for(i=0;i<=n;i++)
        if(f[i])
            mx++;
        printf("%d\n",mx);
    }
    return 0;
}

