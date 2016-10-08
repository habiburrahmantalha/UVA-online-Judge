#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;


int main()
{

    long long a,b,c,d,x,y,tc,i;
    string str;
    scanf("%lld",&tc);
    while(tc--)
    {
        cin>>str;
        a=0;b=1;c=1;d=0;
        x=1;
        y=1;
        for(i=0;i<str.size();i++)
        {

            if(str[i]=='R')
            {
                a=x;
                c=y;
            }
            if(str[i]=='L')
            {
                b=x;
                d=y;
            }
            x=a+b;
            y=c+d;
        }
        printf("%lld/%lld\n",x,y);

    }
    return 0;
}
