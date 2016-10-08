#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<cmath>

#define N 1000001

using namespace std;

bool mark [N+10];

void sieve ()
{
    int i,j;
    memset (mark, true, sizeof (mark));
    mark [0] = false;

    for (i = 4; i < N; i += 2 )
        mark [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( mark [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                mark [j] = false;
        }
    }

}

bool revnum(int n)
{
    int i=0,num=0,res[100],j,x;
    double k;
    x=n;
    while(x)
    {
        res[i++]=x%10;
        x/=10;
    }
    k=i-1;
    for(j=0;j<i;j++)
    num+=res[j]*((int)pow(10.0,k--));
    //printf("%d\n",num);
    if(mark[num] && num!=n)
    return true;
    else
    return false;
}

int main()
{
    sieve();
    int x;
    while(scanf("%d",&x)==1)
    {
        if(!mark[x])
        printf("%d is not prime.\n",x);
        else if( mark[x] && revnum(x) && x >9 )
        printf("%d is emirp.\n",x);
        else if(mark[x])
        printf("%d is prime.\n",x);
    }
    return 0;
}
