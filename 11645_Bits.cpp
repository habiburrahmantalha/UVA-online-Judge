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


int main()
{
    int t=1,tc,cnt;
    long long x;
    bool f;
    while(scanf("%lld",&x)==1 && x>=0)
    {
        int cnt = 0;
        f=false;
        while(x)
        {
            if(f)
            cnt++;

            if(x&1)
            {
                f=true;
                cout<<"1";
            }
            else
            {
                cout<<"0";
                f=false;
            }
            x>>=1;
        }
        printf("Case %d: %d\n",t++,cnt);

    }
    return 0;
}
