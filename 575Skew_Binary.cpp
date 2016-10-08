#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
    char x[50];
    int sum,i,p,l;
    while(1)
    {
        scanf("%s",x);
        if(x[0]=='0')
        break;
        l=strlen(x);
        p=l;
        sum=0;
        for(i=0;i<l;i++)
        {
            sum+=(x[i]-'0')*(pow(2,p)-1);
            p--;
        }
        printf("%d\n",sum);
    }
    return 0;
}
