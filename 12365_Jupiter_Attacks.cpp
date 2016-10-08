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
#define LL long long
#define LSOne(x) (x&-x)
#define p2(p) (p*p)

LL ft[100010],L;

LL bigMod (LL x, LL p,LL m)
{

    if ( p == 0 ) return 1;
    if ( p % 2 == 0 ) return p2 (bigMod(x, p / 2,m)) % m;
    return ( (x % m) * (bigMod(x, p - 1,m) % m) ) % m;
}

void ft_adjust(int i,LL x,LL m)
{
    for(;i<=L;i+=LSOne(i))
    {
        ft[i]+=x;
        ft[i]%=m;
        if(i==0)
        break;
    }
}
LL ft_rsq1(int i,LL m)
{
    LL sum=0;
    for(;i>=0;i-=LSOne(i))
    {
        sum+=ft[i];
        sum%=m;
        if(i==0)
        break;
    }
    return sum%m;
}
LL ft_rsq2(int i,int j,LL m)
{
    if(i==0)return ft_rsq1(j,m)%m;
    else return (ft_rsq1(j,m)-ft_rsq1(i-1,m)+m)%m;
}
int main()
{

    string str;
    int i,j,k;
    LL x,B,P,N;
    while(scanf("%lld %lld %lld %lld",&B,&P,&L,&N) && B+P+L+N)
    {
        memset(ft,0,sizeof(ft));
        for(i=0;i<N;i++)
        {
            cin>>str;
            if(str=="E")
            {
                scanf("%d %lld",&j,&x);
                j--;
                ft_adjust(j,(x*bigMod(B,L-(j+1),P))%P,P);
                cout<<"->"<<ft[j]<<endl;
            }
            else if(str=="H")
            {
                scanf("%d %d",&j,&k);
                j--;
                k--;
                cout<<ft_rsq1(j-1,P)<<" "<<ft_rsq1(k,P)<<endl;
                printf("%lld\n",ft_rsq2(j,k,P));

            }

        }
        printf("-\n");
    }
    return 0;
}
