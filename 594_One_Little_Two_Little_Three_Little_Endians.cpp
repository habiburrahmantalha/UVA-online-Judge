//Problem Type :
//Time :
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

void print(long long p)
{
    string s="";
    for(int i=0;i<32;i++)
    {
        if(p&1)
        s+="1";
        else
        s+="0";
        p>>=1;
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
}
int main()
{
    //cout<<(1<<24);
    long long n,m,i,j,x,y;
    while(scanf("%lld",&n)==1)
    {
        m=n;
        //print(n);

        for(i=0,j=24;i<8;i++,j++)
        {
            x=n&(1<<i);
            y=n&(1<<j);

            if(x)
            {
                if(!y)
                n=n|(1<<j);
            }
            else
            {
                if(y)
                n=n-(1<<j);
            }

            if(y)
            {
                if(!x)
                n=n|(1<<i);
            }
            else
            {
                if(x)
                n=n-(1<<i);
            }
            //print(n);

        }

        for(i=8,j=16;i<16;i++,j++)
        {
            x=n&(1<<i);
            y=n&(1<<j);

            if(x)
            {
                if(!y)
                n=n|(1<<j);
            }
            else
            {
                if(y)
                n=n-(1<<j);
            }

            if(y)
            {
                if(!x)
                n=n|(1<<i);
            }
            else
            {
                if(x)
                n=n-(1<<i);
            }

            //print(n);
        }
        //print(n);
        printf("%lld converts to %lld\n",m,n);
    }
    return 0;
}
