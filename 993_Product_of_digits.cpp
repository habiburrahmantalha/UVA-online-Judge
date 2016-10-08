#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int i,n,in,tc;
    char a[100];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        in=0;
        for(i=9;i>1;i--)
        {
            while(n%i==0 && n)
            {
                a[in++]=i+48;
                n/=i;
            }

        }
        if(n==0)
            a[in++]=1+48;

        if(n<10)
        {
            if(in==0 && n==1)
                a[in++]=n+48;
            if(in>0 && n!=1)
            a[in++]=n+48;
            a[in]=0;
            sort(a,a+in);
            if(a[0]=='0')
            {
                a[0]=a[1];
                a[1]='0';
            }
            printf("%s\n",a);
        }
        else
            printf("-1\n");
    }
    return 0;
}
