#include<stdio.h>


long long C[210];
void cola()
{
    long long count,y,i,x;
    for(i=1;i<=200;i++)
    {
        x=i;
        count=x;
        while(1)
        {
            if(x==1)
            break;
            if(x==2)
            {
                count++;
                break;
            }
            y=x/3;
            count+=y;
            x%=3;
            x+=y;
        }
        C[i]=count;
        //printf("%lld %lld\n",i,C[i]);
    }
}

int main()
{
    long long x;
    cola();
    while(scanf("%lld",&x) ==1 && x)
    {

        printf("%lld\n",C[x]);
    }
    return 0;
}
