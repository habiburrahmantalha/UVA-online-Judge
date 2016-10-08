#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int tc,i,a,b,x,mn,mx;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&a,&b);
        mx=0;
        mn=0;
        for(i=0;i<b;i++)
        {
            scanf("%d",&x);
            mx=max(mx,max(x,a-x));
            mn=max(mn,min(x,a-x));
        }
        printf("%d %d\n",mn,mx);
    }
    return 0;
}
