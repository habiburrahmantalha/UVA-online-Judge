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
#define p2(p) (p*p)
#define LL int
LL bigMod (LL x, LL p,LL m)
{

    if ( p == 0 ) return 1;
    if ( p % 2 == 0 ) return p2 (bigMod(x, p / 2,m)) % m;
    return ( (x % m) * (bigMod(x, p - 1,m) % m) ) % m;
}


int main()
{
    while(cin>>a>>b && a!="0" && b!="0")
    {
        printf("%d\n",bigMod(a[a.size()-1]-'0',))
    }
    return 0;
}
