#include<stdio.h>

int main()
{
    int p,q,sum,i,a,b;
    while(scanf("%d %d",&p,&q))
    {

        if(p<0 && q<0)
            break;
        sum=0;
        if(q-p<20)
        {
            for(i=p;i<=q;i++)
            {
                if(i%10==0)
                    sum+=i/10;
                else
                    sum+=i%10;
            }
        }
        else
        {

            while(p%10!=0)
            {
                sum+=p%10;
                p++;
            }
            while(q%10!=0)
            {
                sum+=q%10;
                q--;
            }
            a=p/10;
            b=q/10;

            sum+=(b-a)*45+s;

        }
        printf("%d\n",sum);
    }
    return 0;
}
