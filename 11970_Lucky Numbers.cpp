#include<stdio.h>
#define N 1000000000
#include<vector>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

long long S[1000000],L[1000000],n,SQ[1000000],lim;

void square()
{

    long long i,j=0;

    for(i=1;i*i<N;i++)
    {
        S[j]=i*i;
        SQ[j++]=i;
    }

}
void lucky()
{

    long long i,x;
    lim=0;
    for(i=0;S[i]<n;i++)
    {
        x=n-S[i];
        if(x%SQ[i]==0)
        L[lim++]=x;
    }
    sort(L,L+lim);

}
int main()
{
    square();
    long long tc,t,i;

    scanf("%lld",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%lld",&n);
        lucky();
        printf("Case %lld:",t);
        for(i=0;i<lim;i++)
        printf(" %lld",L[i]);
        printf("\n");
    }
}
