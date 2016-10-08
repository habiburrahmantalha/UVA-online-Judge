#include<stdio.h>
#include<algorithm>
using namespace std;

int f[13],h[13];

void fact()
{
    int i;
    f[0]=1;
    for(i=1;i<=12;i++)
        f[i]=i*f[i-1];
}

void hat()
{
    h[2]=1;
    h[3]=2;
    for(int i=4;i<=12;i++)
    {
        h[i]=(i-1)*(h[i-1]+h[i-2]);
    }
}
int main()
{
    fact();
    hat();
    int tc,n,sum,x;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        printf("%d/%d\n",h[n],f[n]);

    }
    return 0;
}
