#include<stdio.h>

long int max,value;

void cal( long int a, long int b)
{
    long int i,count;
    max=0;
    for(i=a;i<=b;i++)
    {
        a=i;
        count=0;

        do {
            if(a&1)
            a=3*a+1;
            else
            a=a/2;

            count++;
        }while(a!=1);

        //printf("%lld %lld\n",i,count);
        if(count>max)
        {
            max=count;
            value=i;
        }
    }

}
int main()
{
     long int i,j;
    while(scanf("%ld %ld",&i,&j))
    {
        if(i==0 && j==0)
        break;
        if(i>j)
        {
            i^=j;
            j^=i;
            i^=j;
        }

        cal(i,j);
        printf("Between %ld and %ld, %ld generates the longest sequence of %ld values.\n",i,j,value,max);

    }
    return 0;

}
