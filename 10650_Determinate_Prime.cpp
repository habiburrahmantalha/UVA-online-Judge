#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

#define N 32010

vector<int>p;
bool prime[N+5];
int Index;
struct DP
{
  int s,d,e;
};
DP D[N+5];

void sieve_prime()
{
    int i,j;
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(i=4;i<N;i+=2)
    prime[i]=false;
    for(i=3;i*i<N;i++)
    if(prime[i])
    for(j=i*i;j<N;j+=2*i)
    prime[j]=false;

    for(i=0;i<N;i++)
    if(prime[i])
    p.push_back(i);
    //printf("%d\n",p.size());
}
void determinate_prime()
{
    int a,b,i,j,last=0;
    Index=0;
    for(i=0;i<p.size();i++)
    {
        if(p[i+1]-p[i]==p[i+2]-p[i+1])
        {
            //printf("%d ",p[i]);
            D[Index].s=p[i];
            D[Index].d=j=p[i+1]-p[i];
            a=i+2;
            b=i+3;
            while(p[b]-p[a]==j)
            {
                a=b;
                b++;
            }
            D[Index++].e=p[a];
            if(last==p[a])
            Index--;
            last=p[a];
        }
    }


}

int main()
{
    //freopen("out.txt","w",stdout);
    sieve_prime();
    determinate_prime();
    //printf("%d\n",Index);
    int a,b,i,j,last;
    while(scanf("%d %d",&a,&b) && a+b)
    {
        if(a>b)
        {
            a^=b;
            b^=a;
            a^=b;
        }
        last=0;
        for(i=0;i<Index;i++)
        {
            if(D[i].s>=a && D[i].e<=b)
            {
                if(last==D[i].e)
                continue;
                for(j=D[i].s;j<D[i].e;j+=D[i].d)
                printf("%d ",j);
                printf("%d\n",j);
                last=D[i].e;
            }
        }
    }
    return 0;
}

