#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
    int tc,t=1;
    long long N,S1,S2,V1,V2,sum1,sum2;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%lld %lld %lld %lld %lld",&N,&S1,&V1,&S2,&V2);


        sum1=V1*(floor(N/S1)) + (floor((N%S1)/S2))*V2;
        sum2=V2*(floor(N/S2)) + (floor((N%S2)/S1))*V1;
        if(sum1>sum2)
        printf("Case #%d: %lld\n",t++,sum1);
        else
        printf("Case #%d: %lld\n",t++,sum2);

    }
    return 0;
}
