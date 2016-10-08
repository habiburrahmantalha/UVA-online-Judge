#include<stdio.h>
#include<math.h>

int main()
{
    int t=1,tc,res;
    double x,tax;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%lf",&x);

        tax=0;
        x-=180000;


        if(x>0)
        {
            if(x<=300000)
            {
                tax=x*10/100;
                x-=x;
            }
            else
            {
                tax=30000;
                x-=300000;
            }
        }
        if(x>0)
        {
            if(x<=400000)
            {
                tax+=x*15/100;
                x-=x;
            }
            else
            {
                tax+=60000;
                x-=400000;
            }
        }
        if(x>0)
        {
            if(x<=300000)
            {
                tax+=x*20/100;
                x-=x;
            }
            else
            {
                tax+=60000;
                x-=300000;
            }
        }
        if(x>0)
        {

            tax+=x*25/100;
            x-=x;

        }
        res=ceil(tax);
        if(res>0 && res<2000)
        res=2000;
        printf("Case %d: %d\n",t++,res);


    }
    return 0;
}
