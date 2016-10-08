#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 100010
#include<vector>
#define LL long long
using namespace std;

bool prime[N+10];
vector<int> Prime;
int a[N+10],b[N+10];

void sieve()
{
    int i,j;
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;

    for(i = 4; i < N; i+=2)
    prime[i] = false;
    for(i = 3; i * i < N; i++)
    {
        if(prime[i])
        for (j = i * i; j < N; j += 2 * i )
        prime[j]=false;

    }
    for(j = 1; j < N; j++)
    if(prime[j])
    Prime.push_back(j);

    //printf("%d",Prime.size());
}
void divisor()
{
    int i,j;
    for ( i = 1; i <N; i++ )
	{
		for ( j = i; j <N; j+=i )
			a[j]+=1;
	}
}
int  SOD(int n)
{
    if(prime[n])
    return n+1;
    int sod=1,a=0;
    int i;
    for ( i = 0;Prime[i]*Prime[i]<= n; i ++ )
    {
        a=0;
        while(n%Prime[i]==0)
        {
            n=n/Prime[i];
            a++;
        }
        sod*=(pow(Prime[i],a+1)-1)/(Prime[i]-1);
        //printf("%lld %d",sod,i);
        if(n==1)
        return sod;


    }
    if(n>1)
        sod*=(pow(n,2)-1)/(n-1);
    return sod;
}
void precal()
{
    sieve();
    divisor();
    for(int i=1;i<=N;i++)
    b[i]=SOD(i);
    //for(int i=0;i<10;i++)
    //printf("%d %d\n",a[0],b[8]);
}

int main()
{
    int tc,i,j,k,l;
    LL sod,nod;
    precal();
    scanf("%d",&tc);
    while(tc--)
    {
        sod=nod=0;
        scanf("%d %d %d",&i,&j,&k);
        l=i;
        while(l%k!=0)
            l++;

        for(;l<=j;l+=k)
        {

                nod+=a[l];
                sod+=b[l];

        }
        printf("%lld %lld\n",nod,sod);
    }
    return 0;
}
