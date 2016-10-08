#include<string.h>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<unsigned long long>x;

void precal()
{
    unsigned long long a=1;
    unsigned long long b=1;
    while(a<=1000000000000000)
    {
        x.push_back(a-b);
        b++;
        a+=b;
    }
}
int main()
{
    unsigned long long n;
    unsigned long long t=1, LW;
    precal();

    while(scanf("%llu",&n) && n)
    {
        LW=(unsigned long long)(upper_bound(x.begin(),x.end(),n)-x.begin());
        printf("Case %llu: %llu\n",t++,LW+2);
    }
    return 0;
}
