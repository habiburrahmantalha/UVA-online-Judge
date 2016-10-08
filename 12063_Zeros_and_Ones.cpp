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
long long N,K;

void print_B(long long x)
{
    if(x==0)
        return;

    print_B(x>>1);
    if(x&1)
    printf("1");
    else
    printf("0");

}
bool valid(long long x)
{
    if(x%K!=0)
    return false;

    int c=0;
    while(x)
    {
        if(x&1)
        c++;
        x>>=1;
    }

    if(c==N/2)
    return true;
    return false;
}
int main()
{
    long long tc,x,y,i;
    scanf("%lld",&tc);
    while(tc--)
    {
        cin>>N>>K;
        x=1;
        x<<=N-1;


        for(i=0;i<N/2-1;i++)
        x|=1<<i;
        y=0;
        for(i=0;i<N;i++)
        {
            y<<=1;
            if(i<N/2)
            y|=1;

        }
        for(i=x;i<=y;i++)
        {
            if(valid(i))
            {
                printf("+");
                print_B(i);
                printf(" %lld\n",i);
            }
            else
            {
                printf("-");
                print_B(i);
                printf(" %lld\n",i);
            }
        }


    }
    return 0;
}
