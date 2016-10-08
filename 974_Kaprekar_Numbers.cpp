#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
#define LL long long

vector<LL>K;

LL POW(LL x)
{
    LL y=1;
    while(x--)
    y*=10;
    return y;
}
bool valid(LL p,LL x,LL y)
{
    LL a=y/p;
    LL b=y%p;

    if(a && b && (a+b == x))
    return true;

    return false;
}
bool kaprekar_numbers(LL x)
{
    LL h,p;
    LL y=x*x;
    LL d=ceil(log10(y));
    //printf("%lld %lld %lld\n",x,y,d);

    for(LL i=0;i<d;i++)
   {


        p=POW(i);
        if(valid(p,x,y))
        return true;
   }

    return false;
}
void precal()
{
    LL i;
    for(i=1;i<=40000;i++)
    if(kaprekar_numbers(i))
    K.push_back(i);
}
int main()
{
    precal();
    //for(int i=0;i<K.size();i++)
    //printf("%lld ",K[i]);
    int tc,t=1,LW,i;
    LL a,b;
    bool f;
    scanf("%d",&tc);
    while(tc--)
    {
        f=false;
        scanf("%lld %lld",&a,&b);

        LW=int (lower_bound(K.begin(),K.end(),a) - K.begin());
        printf("case #%d\n",t++);
        for(i=LW;K[i]<=b && i<K.size();i++)
        {
            f=true;
            printf("%lld\n",K[i]);
        }
        if(!f)
        printf("no kaprekar numbers\n");
        if(tc)
        printf("\n");

    }
    return 0;
}
