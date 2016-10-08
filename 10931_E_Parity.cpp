#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

void bin(long long x)
{
    long long y=x,i,z,sum=0;
    vector<long long> B;
    while(y)
    {
        z=y%2;
        B.push_back(z);
        sum+=z;
        y/=2;
    }
    reverse(B.begin(),B.end());
    printf("The parity of ");
    for(i=0;i<B.size();i++)
        printf("%lld",B[i]);
    printf(" is %lld (mod 2).\n",sum);
}

int main()
{
    long long x;
    while(scanf("%lld",&x) && x)
    {
        bin(x);
    }
    return 0;
}
