#include<stdio.h>
#include<math.h>
#include<string>
#define LL long long
#define N 100
#include<vector>
using namespace std;

vector<string> sf;

LL m,af[21][500001],x;

LL fib(LL n)
{
    if(n<2)
        return n;
    if(n<500001)
        return af[x][n];

    if(n%2==0)
        return ((2*fib((n/2)-1)+fib(n/2))*fib(n/2))%m;
    else
        return ((fib((n+1)/2)*fib((n+1)/2))+(fib(((n+1)/2)-1)*fib(((n+1)/2)-1)))%m;
}
void precal()
{
    string str;
    str="0";
    sf.push_back(str);
    str="1";
    sf.push_back(str);
    for(int i=2;i<10;i++)
    {
        str="";
        str+=sf[i-2];
        str+=sf[i-1];
        sf.push_back(str);
    }
   for(int i=0;i<10;i++)
        printf("%s\n",sf[i].c_str());
}
int main()
{
    precal();
    /*
    long long n,f;

    while(scanf("%lld %lld",&n,&x)==2)
    {
        if(n==0 || x==0)
        {
            printf("0\n");
            continue;
        }
        m=pow(2,x);
        f=fib(n);
        printf("%lld\n",f);

    }
    */
    return 0;
}
