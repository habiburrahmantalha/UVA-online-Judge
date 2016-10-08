#include<stdio.h>
#define N 502
int a[510][510];
int gcd(int m, int n)
{
   if(m == n)
      return m;
   else if (m > n)
      return gcd(m-n, n);
   else
      return gcd(m, n-m);
}

void precal()
{
    for(int i=1;i<N;i++)
    {
        for(int j=1;j<N;j++)
            a[i][j]=gcd(i,j);
    }
}
int main()
{
    precal();
    int i,j,n;
    long long sum;
    while(scanf("%d",&n) && n)
    {
        sum=0;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n ;j++)
            sum+=a[i][j];
        printf("%lld\n",sum);


    }

    return 0;
}
