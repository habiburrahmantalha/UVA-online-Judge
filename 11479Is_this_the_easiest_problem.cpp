#include<stdio.h>
#include<algorithm>
#define LL long long
using namespace std;

bool Invalid(LL a,LL b,LL c)
{

    if ((a + b) <= c || (a + c) <= b || (b + c) <= a)
    return true;
    else
    return false;

}

bool Equilateral(LL a,LL b,LL c)
{
    if(a==b && b==c)
    return true;
    else
    return false;
}

bool Isosceles(LL a,LL b,LL c)
{
    if(a==b || b==c || a==c)
    return true;
    else
    return false;
}

int main()
{
    LL tc,a,b,c,i;

    scanf("%lld",&tc);

    for(i=1;i<=tc;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);

        printf("Case %lld: ",i);

        if(Invalid(a,b,c))
        printf("Invalid\n");
        else
        {
            if(Equilateral(a,b,c))
            printf("Equilateral\n");
            else if(Isosceles(a,b,c))
            printf("Isosceles\n");
            else
            printf("Scalene\n");
        }
    }
    return 0;
}
