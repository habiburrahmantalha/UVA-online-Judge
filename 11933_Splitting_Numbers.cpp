#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;

int num[1000],a[1000],b[1000];

void to_dec(int in);
void to_bin(int x)
{
    memset(num,0,sizeof(num));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int in=0,i,y=0;
    while(x)
    {
        num[in++]=x%2;
        x/=2;
    }

    for(i=0;i<in;i++)
    {
        if(num[i])
        if(y==0)
        {
            a[i]=1;
            y=(y+1)%2;
        }
        else
        {
            b[i]=1;
            y=(y+1)%2;
        }
    }
    reverse(num,num+in);
    reverse(b,b+in);
    reverse(a,a+in);
    to_dec(in);
}
void to_dec(int in)
{
    int dec=0,i;
    for(i=0;i<in;i++)
        dec+=a[i]*pow(2,in-i-1);
    printf("%d",dec);
    dec=0;
    for(i=0;i<in;i++)
        dec+=b[i]*pow(2,in-i-1);
    printf(" %d\n",dec);
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        to_bin(n);
    }
    return 0;
}
