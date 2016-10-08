#include<stdio.h>
#include<string.h>
#define N 50
int n,a[20];
bool b[20];
bool prime[50+5];
void sieve ()
{
    int i,j;
    memset (prime, true, sizeof (prime));
    prime [0] = prime [1] = false;

    for (i = 4; i < N; i += 2 )
        prime [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( prime [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                prime [j] = false;
        }
    }
}
bool available(int num,int in)
{
    if(in==n-1)
    {
        if(prime[a[in-1]+num] && prime[1+num])
            return true;
        return false;
    }
    if(prime[a[in-1]+num])
        return true;
    return false;


}
//int c;
void ring(int x)
{
    int i;
    if(x==n)
    {
        //c++;
        //return;
        printf("%d",a[0]);
        for(i=1;i<n;i++)
        printf(" %d",a[i]);
        printf("\n");
        return;
    }
    for(i=2;i<=n;i++)
    {
        if(b[i])
        {
            if(available(i,x))
            {
                b[i]=false;
                a[x]=i;
                ring(x+1);
                b[i]=true;
            }
        }
    }
}

int main()
{
    sieve ();
    int t=1;
    bool f=false;
    while(scanf("%d",&n)!=EOF)
    {
        if(f)
            printf("\n");
        //c=0;
        printf("Case %d:\n",t++);
        if(n%2!=0 && n!=1)
        {
            printf("\n");
            continue;
        }
        a[0]=1;
        memset(b,true,sizeof(b));

        ring(1);
        //printf("%d\n",c);
        //printf("\n");
        f=true;
    }
    return 0;
}
