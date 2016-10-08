#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

map<long long,long long>digit;
void precal()
{
    long long x,i,j,y,z,k,last;

    map<long long,long long> :: iterator it;
    last=0;
    x=1;
    for(i=0;i<10;i++)
    {
        for(j=1;j<10;j++)
        {
            y=x*j;
            z=0;


                for(k=y-x;k>0;k-=x)
                    z+=k;
                digit[y]=last*(y/x)+z+y/x;



            //printf("%lld %lld %lld %lld\n",y,z,y/x,digit[y]);
        }
        last = digit[y];
        x*=10;
    }
}
long long SumOfDigit(long long a)
{
    long long j,sum=0,i;
    for(i=1;i<=a;i++)
    {
        j=i;
        while(j)
        {
            sum+=j%10;
            j/=10;
        }
    }
    return sum;
}
int main()
{
    precal();
    long long a,b,x,s1,s2,y;
    while(scanf("%lld",&a)==1 && a)
    //while(scanf("%lld %lld",&a,&b)==2 && a+b)
    {
        x=10;
        s1=0;
        cout<<SumOfDigit(a)<<" ";
        while(a)
        {
            y=a%x;
            s1+=digit[y];
            a-=y;
            x*=10;


        }
        cout<<s1<<endl;continue;
        x=10;
        s2=0;
        while(b)
        {
            y=b%x;
            s2+=digit[y];
            b-=y;
            x*=10;


        }
        cout<<s1<<" "<<s2<<" "<<s2-s1<<endl;
    }
    return 0;
}
