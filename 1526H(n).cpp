#include<stdio.h>
#include<math.h>

#define N 70000
long long h[N+5];
long long H(int n){

      long long res = 0,p;

     for( int i = 1; i <= n; i=i+1 ){

            res = (res + n/i);

      }
    //p=sqrt(n);
     //return res*2-pow(p,2);
        return res;
}

void gen_H()
{
    for(long long i=1;i<100;i++)
    {
        h[i]=H(i);
    }
}
int main()
{
    long long tc,x,i,p;
    gen_H();
    scanf("%lld",&tc);

    while(tc--)
    {
        scanf("%lld",&x);

        //printf("%lld\n",H(x));
        p=sqrt(x);
        printf("%lld\n",p);
        printf("%lld\n",h[p]);
        printf("%lld\n",h[p]*2-p*p);
    }
}
