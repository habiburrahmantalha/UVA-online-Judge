#include<stdio.h>
#include<algorithm>

using namespace std;

long long B[100];

void rat()
{
    long long i;
    B[0]=0;
    B[1]=1;
    for(i=2;i<64;i++)
    {
        B[i]=B[i-1]*2;
    }
}

int main()
{
    rat();
    long long x;
    int tc,t,i;

    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%lld",&x);
        x++;
        for(i=0;i<64;i++)
        {
            if(x<=B[i])
                break;
        }
        printf("Case %d: %d\n",t,i-1);
    }
}
