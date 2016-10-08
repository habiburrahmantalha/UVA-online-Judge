#include<stdio.h>
#include<string.h>


void precal()
{
    long long c=0,i=2,j,s,t;
    while(c<11)
    {
        s=(i*(i-1))/2;
        j=i+1;
        t=0;
        while(t<s)
        {
            t+=j;
            j++;
            if(s==t)
            {
                printf("%lld %lld\n",i,j-1);
                c++;
            }
        }
        i++;

    }
}
int main()
{
    precal();
}
