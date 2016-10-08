#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

#define N 1000010

int prime[N+5];
int p_diff[N+5];

void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    int i,j;
    for(i=4;i<N;i+=2)
    prime[i]=false;

    for (i = 3; i * i <= N; i++ )
        if ( prime[i] )
            for (j = i * i; j < N; j += 2 * i )
                prime[j] = false;

}

void prime_diff()
{
    int x=2;
    for(int i=3;i<N;i++)
    {
        if(prime[i])
        {
            p_diff[i]=i-x;
            x=i;
        }
    }
    //for(int i=30+1;i<50;i++)
    //if(p_diff[i])
    //printf("%d %d    ",i,p_diff[i]);
}

int main()
{
    sieve();
    prime_diff();
    int tc,a,b,i,max,maxi,count,frequency[200];
    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d %d",&a,&b);

        memset(frequency,0,sizeof(frequency));
        for(i=a;i<b;i++)
        if(prime[i])
        break;

        for(i=i+1;i<=b;i++)
        {
            if(p_diff[i])
            frequency[p_diff[i]]++;
        }
        max=0;
        for(i=0;i<200;i++)
        if(frequency[i])
        {
            //printf("%d %d ",i,frequency[i]);
            if(max<frequency[i])
            {
                max=frequency[i];
                maxi=i;
            }
        }
        count=0;
        for(i=0;i<200;i++)
        if(frequency[i])
        {
            if(max==frequency[i])
            count++;
            if(count>1)
            {
                max=0;
                break;
            }
        }

        if(max==0)
        printf("No jumping champion\n");
        else
        printf("The jumping champion is %d\n",maxi);

    }
    return 0;
}
