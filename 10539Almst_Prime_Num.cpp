#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

using namespace std;

#define N 1000000

vector <int> primeList;
vector<long long> AP;

void sieve ()
{
    int mark[N+5];
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for ( int i = 4; i < N; i += 2 )
        mark [i] = false;

    for ( int i = 3; i * i <= N; i++ )
    {
        if ( mark [i] )
        {
            for ( int j = i * i; j < N; j += 2 * i )
                mark [j] = false;
        }
    }

    primeList.clear ();
    primeList.push_back (2);

    for ( int i = 3; i < N; i += 2 )
    {
        if ( mark [i] )
            primeList.push_back (i);
    }

    //printf ("%d\n", primeList.size ());
}

void almstPrime()
{
    long long x,y,i;
    for(i=0;i<primeList.size();i++)
    {
        y=primeList[i];
        AP.push_back(y*y);
        x=y*y;
        while(1)
        {
            x*=primeList[i];
            if(x>1000000000000)
            break;
            AP.push_back(x);
        }
    }
    sort(AP.begin(),AP.end());
}

int main()
{
    long long a,b;
    int tc,l,u;
    sieve();
    almstPrime();

    scanf("%lld",&tc);

    while(tc--)
    {
        scanf("%lld %lld",&a,&b);
        l=(int)(lower_bound(AP.begin(),AP.end(),a)-AP.begin());
        u=(int)(upper_bound(AP.begin(),AP.end(),b)-AP.begin());
        printf("%d\n",u-l);
    }
    return 0;
}
