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
int T[110];
void precal()
{
    LL s=0;
    for(LL i=1;i<110;i++)
    {
        s+=bigMod(i,i,10);
        s%=10;
        T[i]=s;
        //cout<<i<<" "<<s<<endl;

    }
}
int main()
{
    precal();
    string s;
    while(cin>>s && s!="0")
    {

        if(s.size()==1)
            printf("%d\n",T[s[0]-'0']);
        else
        {
            int x=(s[s.size()-2]-'0')*10+s[s.size()-1]-'0';
            //cout<<"*"<<x<<endl;
            printf("%d\n",T[x]);
        }
    }
    return 0;
}
