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
#define N 4200
bool p[N];
vector<int>prime,v;

void sieve()
{
    memset(p,true,sizeof(p));
    int i,j;
    for(i=2;i<N;i++)
        for(j=i+i;j<N;j+=i)
            p[j]=false;
    for(i=2;i<N;i++)
    if(p[i])prime.push_back(i);
}

int main()
{
    sieve();
    int n,c,i,j,k;
    bool f[N];
    while(scanf("%d",&n) && n)
    //freopen("10015.txt","w",stdout);
    //for(n=1;n<=3501;n++)
    {
        for(i=0;i<n;i++)
        v.push_back(i);
        v.erase(v.begin()+i);
        /*
        memset(f,true,sizeof(f));
        c=0;
        i=0;
        k=0;
        while(c!=n-1)
        {
            j=prime[k];
            while(j)
            {
                if(f[i])
                {
                    //cout<<i<<" ";
                    j--;
                    if(j)
                    i=(i+1)%n;
                }
                else
                    i=(i+1)%n;
            }
            //cout<<i<<"* ";
            f[i]=false;
            k++;
            c++;

        }
        for(i=0;i<=n;i++)
        if(f[i])
        {
            printf("%d,",i+1);
            break;
        }
        */
    }
    return 0;
}
