//Problem Type :
//Time :    .028
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
#define PI 2 * acos (0.0)



int main()
{
    long long  n1,n2,c,i;
    char ch[100];
    while(gets(ch))
    {
        if(sscanf(ch,"%lld %lld",&n1,&n2)==2)
        {
            //scanf("%lld",&n2);


            c=0;
            for(i=n1;i<=n2;i++)
                if(abs(i)%4!=0 && !(i&1))
                    c++;
            //else cout<<i<<" ";
            printf("%lld\n",c);

        }
        else
        {
            if(n1>=0)
            {
                if(n1==0)
                printf("0 0\n");
                else if(n1&1)
                printf("%lld %lld\n",(n1+1)/2,(n1-1)/2);
                else if(n1%4==0)
                printf("%lld %lld\n",(n1/4)+1,(n1/4)-1);
                else if(n1&1)
                printf("Spinster Number.\n");
                else
                printf("Bachelor Number.\n");
            }
            else
            {
                n1=-n1;
                if(n1==0)
                printf("0 0\n");
                else if(n1&1)
                printf("%lld %lld\n",(n1-1)/2,(n1+1)/2);
                else if(n1%4==0)
                printf("%lld %lld\n",(n1/4)-1,(n1/4)+1);
                else if(n1&1)
                printf("Spinster Number.\n");
                else
                printf("Bachelor Number.\n");

            }

        }
    }
    return 0;
}
