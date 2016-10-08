#include<stdio.h>
#include<string.h>

int factor[101][101],factorial[101][101],prime[101];

void sieve()
{
    memset(prime,1,sizeof(prime));
    int i,j;
    prime[0]=prime[1]=0;
    for(i=2;i<101;i++)
    {
        if(prime[i])
            for(j=i+i;j<101;j+=i)
            prime[j]=0;
    }
    //for(i=0;i<101;i++)
    //if(prime[i])
        //printf("%d ",i);
}

void factors()
{
    memset(factor,0,sizeof(factor));
    int i,j,k;
    for(i=2;i<101;i++)
    {
       for(j=2;j<=i;j++)
       {
           if(prime[j])
           {
               k=i;
               if(k%j==0)
               {
                   while(k%j==0)
                   {
                       factor[i][j]++;
                       k/=j;
                   }
               }
           }
       }
    }
}

void factorials()
{
    memset(factorial,0,sizeof(factorial));
    int i,j;
    for(j=0;j<101;j++)
    factorial[2][j]=factor[2][j];
    for(i=3;i<101;i++)
    {
        for(j=0;j<101;j++)
            factorial[i][j]=factor[i][j]+factorial[i-1][j];
    }
}
int main()
{
    //freopen("out.txt","w",stdout);
    sieve();
    factors();
    factorials();
    int x,i,l;
    //for(x=2;x<101;x++)
    while(scanf("%d",&x) && x)
    {
        printf("%3d! =",x);
        l=0;
        for(i=2;i<=x;i++)
        {
            if(prime[i])
            {
                if(l==15)
                    printf("\n      ");

                printf("%3d",factorial[x][i]);
                l++;
            }
        }
        printf("\n");
    }
}
