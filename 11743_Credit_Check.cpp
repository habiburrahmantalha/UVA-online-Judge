#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int sum_double(string str)
{
    int i,a,x,sum=0;
    for(i=0;i<16;i+=2)
    {
        x=str[i]-48;
        x*=2;
        if(x>9)
        {
            while(x)
            {
                sum+=x%10;
                x/=10;
            }
        }
        else
        sum+=x;
    }

    return sum;

}
int sum_single(string str)
{
    int i,a,x,sum=0;
    for(i=1;i<16;i+=2)
    {
        x=str[i]-48;
        sum+=x;
    }

    return sum;
}
int main()
{
    int tc,n,a,b,c;
    string str,num;
    scanf("%d",&tc);

    while(tc--)
    {
        n=4;
        num="";
        while(n--)
        {
            cin>>str;
            num+=str;

        }
        a=sum_double(num);
        b=sum_single(num);
        c=a+b;
        if(c%10==0)
            printf("Valid\n");
        else
            printf("Invalid\n");
    }
    return 0;
}
