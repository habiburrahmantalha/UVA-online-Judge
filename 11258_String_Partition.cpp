#include<string>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;

unsigned long long tonum(string str)
{
    reverse(str.begin(),str.end());
    unsigned long long num=0;
    for(int i=0;i<str.size();i++)
    {
        num+=(str[i]-'0')*pow(10,i);
    }
    return num;
}
int main()
{
    unsigned long long tc,i,sum;
    unsigned long long  x=2147483647,y,z;
    string str,num,num2;
    scanf("%llu",&tc);
    getchar();
    while(tc--)
    {
        sum=0;
        cin>>str;
        num="";

        for(i=0;i<str.size();i++)
        {
            num+=str[i];
            y=tonum(num);
            //cout<<y<<endl;
            if(y<=x)
                z=y;
            else
            {

                sum+=z;

                num=str[i];
                z=tonum(num);
            }
        }

        sum+=z;
        printf("%llu\n",sum);
    }
    return 0;
}
