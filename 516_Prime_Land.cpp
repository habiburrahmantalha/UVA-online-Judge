//Problem Type :    prime
//Time :    0.024
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<sstream>
using namespace std;
#define PI 2 * acos (0.0)

int prime[32770];
vector<int>p;

void sieve()
{
    memset(prime,1,sizeof(prime));
    int i,j;
    for ( i = 2;i*i <=32767; i ++ )
	{
		if ( prime[i] )
		{
			for ( j = i + i; j <= 32767; j += i )
				prime[j] = 0;
		}
	}
	for(i=2;i<=32767;i++)
        if(prime[i])
            p.push_back(i);

}
int POW(int x,int p)
{
    int y=1;
    for(int i=1;i<=p;i++)
    y*=x;

    return y;
}

void factor(int n)
{

    int i,c;
    vector<int>r;
    for(i=0;p[i]*p[i]<=n;i++)
    {
        if(n%p[i]==0)
        {

            c=0;
            while(n%p[i]==0)
            {
                n/=p[i];
                c++;
            }
            r.push_back(c);
            r.push_back(p[i]);
        }
    }
    if(n>1)
    {
        r.push_back(1);
        r.push_back(n);

    }
    reverse(r.begin(),r.end());
    for(i=0;i<r.size();i++)
        if(i==0)
            printf("%d",r[i]);
        else
            printf(" %d",r[i]);

    printf("\n");

}
int main()
{
    sieve();
    int x[100],i,j,n;
    string str;
    while(getline(cin,str) && str!="0")
    {
        stringstream ss(str);
        i=0;
        while(ss>>x[i])
        {
            i++;
        }
        n=1;
        for(j=0;j<i;j+=2)
        n*=POW(x[j],x[j+1]);

        factor(n-1);

    }
    return 0;
}
