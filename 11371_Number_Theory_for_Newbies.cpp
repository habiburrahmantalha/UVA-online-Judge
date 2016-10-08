#include<algorithm>
#include<stdio.h>
#include<string.h>
using namespace std;

bool comp(char a,char b)
{
    return a>b;
}

int main()
{
    char a[20],b[20];
    long long n1,n2,i,j,lb;

    while(scanf("%s",&a)==1)
    {


        strcpy(b,a);
        lb=strlen(b);
        sort(a,a+lb);
        sort(b,b+lb,comp);

        for(i=0;i<lb;i++)
            if(a[i]!='0')
            break;
        a[0]=a[i];
        for(j=i;j>0;j--)
            a[j]='0';


        n1=n2=0;
        j=1;
        for(i=lb-1;i>=0;i--)
        {
            n1+=(a[i]-'0')*j;
            n2+=(b[i]-'0')*j;
            j*=10;
        }


        printf("%lld - %lld = %lld = 9 * %lld\n",n2,n1,n2-n1,(n2-n1)/9);

    }
    return 0;
}
