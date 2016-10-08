#include<stdio.h>
#include<string.h>
int P[30],f[30];
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
    for(i=0;i<=26;i++)
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
    int a,b,i,acorn,tree,tc;
    char s[3000],c;
    scanf("%d",&tc);
    while(tc--)
    {

        reset();
        while(1)
        {
            scanf("%s",s);
            if(s[0]=='*')
                break;
            a=s[1]-'A';
            b=s[3]-'A';
            unionset(a,b);

        }

        getchar();
        memset(f,0,sizeof(f));
        //for(i=0;i<=26;i++)
            //findset(i);
        while(scanf("%c",&c))
        {
            i=c-'A';
            f[findset(i)]++;
            c=getchar();
            if(c=='\n')
                break;
        }
        acorn=tree=0;
        for(i=0;i<=26;i++)
        {
            if(f[i]==1)
                acorn++;
            else if(f[i]>1)
                tree++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n",tree,acorn);

    }
    return 0;
}
