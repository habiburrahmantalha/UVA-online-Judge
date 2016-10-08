#include<stdio.h>
#include<math.h>

#define eps 1e-10
int main()
{
    int t=1;
    double S,B,a,b;
    while(scanf("%lf %lf",&B,&S)==2 && S+B)
    {
        if(B==1)
        printf("Case %d: :-\\\n",t++);
        else
        {
            a=S/B;
            b=(S-1)/(B-1);
            if(a>1.0)
            a=1.0;
            if(b>1.0)
            b=1.0;
            if(a==b)
            printf("Case %d: :-|\n",t++);
            else if(a>b)
            printf("Case %d: :-(\n",t++);
            else if(b>a)
            printf("Case %d: :-)\n",t++);
        }
    }
    return 0;
}
