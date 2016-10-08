#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int N,B;

int num_zero()
{
    int i,j,p,c,noz,k;
    noz=N;
    j=B;
    for (i=2;i<=B;i++)
    {
        if (j%i==0)
        {
            p=0;
            while (j%i==0)
            {
               p++;
               j/=i;
            }
            c=0;
            k=N;
            while (k/i>0)
            {
               c+=k/i;
               k/=i;

            }
            noz=min(noz,c/p);
        }
    }
    return noz;
}
double num_digit()
{
    double ans=0,i;
    for (i=1;i<=N;i++)
    {
        ans+=log(i);
    }
    ans/=log(B);
    ans+=1.0;
    ans=floor(ans);
    return ans;
}
int main()
{
    int noz;
    double nod;
    while (scanf("%d%d",&N,&B)==2)
    {
          noz=num_zero();
          nod=num_digit();
          printf("%d %.0lf\n",noz,nod);
    }
}
