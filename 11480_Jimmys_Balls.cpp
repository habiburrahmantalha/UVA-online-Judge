#include<stdio.h>
#include<string.h>

long long n,x[1000020];
/*
void print()
{
    int i,j,k,c=0;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            for(k=j+1;k<n;k++)
            {
                if(i+j+k==n)
                //printf("%d %d %d\n",i,j,k);
                c++;
            }
        }
    }
    printf("%d %d\n",n,c);
}
*/
void precal()
{
    long long i,a,b,c,d,j;
    x[6]=1;
    i=7;
    a=1;
    b=0;
    c=2;
    while(i<1000020)
    {
        x[i]=x[i-1]+b;
        i++;
        b++;

        for(j=1;j<5;j++)
        {
            x[i]=x[i-1]+a;
            i++;
        }
        a++;


        x[i]=x[i-1]+c;
        i++;
        c++;


    }
}
int main()
{
    precal();
    int t=1;
    //for(n=6;n<25;n++)
    while(scanf("%lld",&n)&& n)
    {
        printf("Case %d: %lld\n",t++,x[n]);
        //print();
    }
    return 0;
}
