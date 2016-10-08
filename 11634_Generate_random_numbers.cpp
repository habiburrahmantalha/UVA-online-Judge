//Problem Type :    cycle finding
//Time :    .048
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

bool f[10000];
long long cnt;
void generate_number(long long n)
{
    if(f[n])
        return;
    else
    {
        f[n]=true;
        n*=n;
        char a[10];

        int i=7,j;
        while(n)
        {
            a[i--]=n%10+'0';
            n/=10;
        }
        for(j=0;j<=i;j++)
        a[j]='0';
        a[6]=0;
        n=atol(a+2);
        cnt++;
        generate_number(n);
        //cout<<n<<endl;
    }
}
int main()
{
    long long n;
    while(scanf("%lld",&n) && n)
    {
        memset(f,false,sizeof(f));
        cnt=0;
        generate_number(n);
        printf("%lld\n",cnt);
    }
    return 0;
}
