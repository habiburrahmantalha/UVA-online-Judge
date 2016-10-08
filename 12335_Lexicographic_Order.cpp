//Problem Type : nth permutation
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

LL fact(LL n)
{
    LL f=1,i;
    for(i=1;i<=n;i++)
    f*=i;
    return f;
}
LL part(LL n,LL m)
{
    int x=0,c=0;
    while(x<=n)
    {
        x+=m;
        c++;
    }
    return c;
}
int main()
{
    int tc,n,l,m;
    string str;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>str>>n;
        l=str.size();
        while(l--)
        {
            n=n%fact(l+1);
            m=part(n,fact(l));
            cout<<n<<" "<<m<<endl;

        }

    }
    return 0;
}
