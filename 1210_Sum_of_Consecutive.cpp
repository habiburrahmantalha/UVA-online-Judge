#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>

#define N 10010

using namespace std;

int mark [N+10];
vector<int>prime;


void sieve ()
{
    int i,j;
    for(i=0;i<=N;i++)
        mark[i]=1;
    //memset (mark, 1, sizeof (mark));
    mark [0] = mark [1] = 0;

    for (i = 4; i < N; i += 2 )
        mark [i] = 0;

    for (i = 3; i * i <= N; i++ )
    {
        if ( mark [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                mark [j] = 0;
        }
    }
    for(i=2;i<+N;i++)
        if(mark[i])
        prime.push_back(i);
    //printf("%d\n",prime.size());

}

void consecutive_sum()
{
    int i,j,sum;
    for(i=0;i<=1231;i++)
    {
        sum=0;
        sum+=prime[i];
        for(j=i+1;j<=1231;j++)
        {
            sum+=prime[j];
            if(sum>10000)
                break;
            mark[sum]++;
        }
    }
}
int main()
{
    sieve();
    consecutive_sum();
    int x;
    while(scanf("%d",&x) && x)
    {
        printf("%d\n",mark[x]);
    }
    return 0;
}

