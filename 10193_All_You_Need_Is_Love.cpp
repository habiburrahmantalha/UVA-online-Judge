#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
using namespace std;

#define N 1000001

using namespace std;

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
vector<long long>fx,fy;
vector<long long> factorial(long long n)
{
    int i;
    vector<long long>f;
    for(i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n%prime[i]==0)
        {
            f.push_back(prime[i]);
            while(n%prime[i]==0)
            {
                n/=prime[i];
            }
        }
    }
    if(n!=1)
    f.push_back(n);

    return f;
}

bool compare()
{

    vector<long long> v(fx.size()+fy.size());
    vector<long long>::iterator it;
    it=set_intersection(fx.begin(),fx.end(), fy.begin(), fy.end(), v.begin());

    if(int(it - v.begin())==0)
    return false;
    else
    return true;
}
int main()
{
    sieve();
    int tc,t=1;
    long long x,y;
    string s1,s2;
    scanf("%d",&tc);
    while(tc--)
    {
        fx.clear();
        fy.clear();
        cin>>s1>>s2;
        x=strtol(s1.c_str(),NULL,2);
        y=strtol(s2.c_str(),NULL,2);

        fx=factorial(x);
        fy=factorial(y);

        if(compare())
        printf("Pair #%d: All you need is love!\n",t++);
        else
        printf("Pair #%d: Love is not all you need!\n",t++);
    }
    return 0;
}
