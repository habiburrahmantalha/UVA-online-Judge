#include<stdio.h>
#include<string.h>
int f[50];
int in;
void fibonacci()
{
    in=0;
    long long a,b,c;
    a=0;
    b=1;
    c=1;
    while(c<=2000000010 )
    {
        f[in++]=c;
        a=b;
        b=c;
        c=a+b;
    }

}

int count(int x)
{
    int c=0;
    int i;
    for(i=in-1;i>=0;i--)
    {
        //printf("%lld %lld\n",x,f[i]);
        if(x==0)
            return c;

        else if(f[i]<=x)
        {

            x-=f[i];
            c++;
        }

    }
    return c;
}
int main()
{
    int tc,n,t=1,i;
    int x;
    long long c;
    fibonacci();
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        c=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
                c*=count(x);
        }
        printf("Case %d: %lld\n",t++,c);
    }
    return 0;
}
