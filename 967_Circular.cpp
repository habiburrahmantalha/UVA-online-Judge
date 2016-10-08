#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<cstdlib>
#define N 1000000
#include<algorithm>
using namespace std;

int mark [N+10],F[N+10];

vector <int> prime,sprime;

void sieve ()
{
    int i,j;
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

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

    prime.clear ();
    prime.push_back (2);
    //int count=0;
    for ( i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            {
                prime.push_back (i);
                //count++;
                //printf("%d ",i);
            }
    }
    //printf("%d",prime.size());
}

bool circular_prime(int x)
{
    string s="";
    int i,y;
    while(x)
    {
        s+=((x%10)+'0');
        x/=10;
    }
    reverse(s.begin(),s.end());
    for(i=0;i<s.size();i++)
    {
        y=atoi(s.c_str());
        if(!mark[y])
        return false;
        rotate(s.begin(),s.begin()+1,s.end());
        //cout<<s<<endl;
    }
    return true;
}
void precal()
{
    int i;
    for(i=0;i<prime.size();i++)
    if(circular_prime(prime[i]))
    sprime.push_back(prime[i]);

}
int main()
{
    sieve();
    precal();
    //circular_prime(197);
    //for(int i=0;i<50;i++)
        //cout<<sprime[i]<<" ";
    int a,b,l,h,res;
    while(scanf("%d",&a) && a>=0)
    {
        scanf("%d",&b);
        l=int (lower_bound(sprime.begin(),sprime.end(),a)-sprime.begin());
        h=int (upper_bound(sprime.begin(),sprime.end(),b)-sprime.begin());
        res=h-l;
        //if(mark[a] && a==b)
        //res++;
        if(res==0)
        printf("No Circular Primes.\n");
        else if(res==1)
        printf("1 Circular Prime.\n");
        else
        printf("%d Circular Primes.\n",res);

    }
    return 0;
}
