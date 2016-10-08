#include<stdio.h>
#include<string.h>

#define LL long long

LL c[1010][310],p[310][310];

void pre_pay_coin()
{
    LL i,j,k;

    memset(c,0,sizeof(c));
    c[0][0]=1;

    for(i=1;i<=300;i++)
        for(j=0;j<=300;j++)
            for(k=0;k<=300;k++)
                if(c[j][k] && k+i<=300)
                    c[j+1][k+i]=c[j+1][k+i]+c[j][k];

    for(i=0;i<=10;i++)
    {
        for(j=0;j<=10;j++)
            printf("%3d ",c[i][j]);
        printf("\n");
    }

}
void pre_coin()
{
    LL i,j;
    memset(p,0,sizeof(p));
    p[0][0]=1;
    for(i=0;i<=300;i++)
        for(j=1;j<=300;j++)
            p[j][i]=c[j][i]+p[j-1][i];
}

void pay(LL N,LL L1,LL L2)
{

    LL coin=0,i,L;
    if(L1>N && L2 >N)
        coin =0;
    else
    {
        if(L1>N)
            L1=N;
        if(L2>N)
            L2=N;
        if(N==0)
        for(i=L1;i<=L2;i++)
            coin+=c[i][N];
        else
        {
            L=L1-1;
            if(L<0)
            L=0;
            coin=p[L2][N]-p[L][N];
        }
    }

    printf("%lld\n",coin);
}
int main ()
{
    pre_pay_coin();
    pre_coin();

    LL N,L1,L2;
    char ch;
    while(scanf("%lld",&N)==1)
    {
        ch=getchar();
        if(ch==10)
            pay(N,0,N);
        else
        {
            scanf("%lld",&L1);
            ch=getchar();
            if(ch==10)
            pay(N,0,L1);
            else
            {
                scanf("%lld",&L2);
                pay(N,L1,L2);
            }
        }
    }

    return 0;
}
