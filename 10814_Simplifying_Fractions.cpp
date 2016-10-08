#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;

int gcd(int m, int n)
{
   if(m == n)
      return m;
   else if (m > n)
      return gcd(m-n, n);
   else
      return gcd(m, n-m);
}

int main()
{
    int tc,a,b,c;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d / %d",&a,&b);
        while(1)
        {
            c=gcd(a,b);
            if(c==1)
            break;
            while(a%c==0 && b%c==0)
            {
                a/=c;

                b/=c;
            }
        }
        printf("%d / %d\n",a,b);
    }
    return 0;
}
