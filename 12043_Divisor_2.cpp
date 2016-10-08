
#include<stdio.h>
#include<math.h>
#define N 100000
int NOD[N+1];
int SOD[N+1];

void gen()
{
    int i,j;
    NOD[1]=1;
    SOD[1]=1;
    for(i=2;i<=N;i++)
    {
        NOD[i]=2;
        SOD[i]=1+i;
    }
    for(i=2;i<=N/2;i++)
    {
        for(j=2;;j++)
        {
            if(i*j>N)break;
            NOD[i*j]+=1;
            SOD[i*j]+=i;
        }
    }
}


int main()
{
    gen();
    int i,j,k,l;
    long long sod,nod;
    int tc;

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
                nod+=NOD[l];
                sod+=SOD[l];
        }
        printf("%lld %lld\n",nod,sod);

    }

    return 0;
}
