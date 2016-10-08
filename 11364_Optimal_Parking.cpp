#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,j,tc,a[110],sum,mn,mx,res,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        mn=100000;
        mx=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(mn>a[i])
            mn=a[i];
            if(mx<a[i])
            mx=a[i];
        }
        res=100000;
        for(i=mn;i<=mx;i++)
        {
            sum=((mx-i)+(i-mn))*2;

            if(res>sum)
            res=sum;
        }
        printf("%d\n",res);


    }
    return 0;
}
