#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;

#define N 10000

bool Prime[N+10];

vector <long long> prime;

void sieve ()
{
    long long i,j;
    memset (Prime, true, sizeof (Prime));
    Prime [0] = Prime [1] = false;

    for (i = 4; i < N; i += 2 )
        Prime [i] = false;

    for (i = 3; i * i <= N; i++ )
    {
        if ( Prime [i] )
        {
            for (j = i * i; j < N; j += 2 * i )
                Prime [j] = false;
        }
    }

    prime.clear ();
    prime.push_back (2);
    //int count=0;
    for ( i = 3; i < N; i += 2 ) {
        if ( Prime [i] )
            {
                prime.push_back (i);
                //count++;
                //printf("%d",i);
            }
    }

}
int B(int a,int c)
{
    int i,fc,fa,j,res=1;
    for(i=0;prime[i]*prime[i]<=c;i++)
    {
        fa=fc=0;
        while(c%prime[i]==0)
        {
            fc++;
            c/=prime[i];
        }

        while(a%prime[i]==0)
        {
            fa++;
            a/=prime[i];
        }

        if(fc>fa)
        for(j=0;j<fc;j++)
        res*=prime[i];
    }
    if(c>1 && a==1)
    res*=c;

    return res;
}
int main()
{
    sieve();
    int tc,a,b,i,c;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&a,&c);
        if(c%a==0)
        {
            printf("%d\n",B(a,c));
        }
        else
        printf("NO SOLUTION\n");
    }
    return 0;
}
