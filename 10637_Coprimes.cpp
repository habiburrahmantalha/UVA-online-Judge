#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int gcd(int a,int b)
{
    if(b)
    return gcd(b,a%b);
    return a;
}
int co_prime[110][110];
int res[45];
int t,n;
void coprime()
{
    int i,j;
    memset(co_prime,0,sizeof(co_prime));
    co_prime[1][1]=1;
    for(i=1;i<=100;i++)
    {
        for(j=i+1;j<=100;j++)
        {
            if(gcd(i,j)==1)
            {
                co_prime[i][j]=1;
                co_prime[j][i]=1;
            }
        }
    }
    /*
    for(i=0;i<=10;i++)
    {
        printf("%d->",i);
        for(j=0;j<=10;j++)
        if(co_prime[i][j])
        printf("%d ",j);
        printf("\n");
    }
    */
}
bool iscoprime(int i,int k)
{
    for(int j=1;j<=k;j++)
    if(!co_prime[res[j]][i])
    {
        //printf("%d %d*\n",res[j],i);
        return false;
    }
    return true;
}
void backtracking(int x,int k,int rem,int sum)
{

    if(k>t)
    return;
    int i;
    res[k]=x;
    if(k==t && sum==n)
    {
        for(i=1;i<t;i++)
        printf("%d ",res[i]);
        printf("%d\n",res[i]);
    }
    else if(k==t-1 && rem>=x && iscoprime(rem,k))
    {

            //return ;
            //printf("%d->",n);
            for(i=1;i<t;i++)
            printf("%d ",res[i]);
            printf("%d\n",rem);


    }
    else
    {
        for(i=x;i<=rem;i++)
        {
            if(iscoprime(i,k))
            {

                backtracking(i,k+1,rem-i,sum+i);
            }
        }
    }
}

int main()
{
    int tc,T=1;
    coprime();
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&t);
        printf("Case %d:\n",T++);
//for(n=100;n<=100;n++)
//for(t=1;t<41&&t<=n;t++)
        for(int i=1;i<=n;i++)
        {
            backtracking(i,1,n-i,i);
        }

    }
    return 0;
}
