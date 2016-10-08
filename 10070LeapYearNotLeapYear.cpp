#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
    long long M4,M100,M400,M15,M55;
    bool LY,H,f=false;
    char year[1000000];
    int len;
    while(cin >> year)
    {
        len=strlen(year);
        if(f==true)
        printf("\n");
        LY=H=false;
        M4=M100=M400=M15=M55=0;

        for(int i=0;i<len;i++)
        {
            M400=(M400*10+year[i]-'0')%400;
            M100=(M100*10+year[i]-'0')%100;
            M4=(M4*10+year[i]-'0')%4;
            M15=(M15*10+year[i]-'0')%15;
            M55=(M55*10+year[i]-'0')%55;
        }
        if((M4==0 && M100!=0) || M400==0)
        {
             printf("This is leap year.\n");
             LY = true;
        }
        if (M15==0)
        {
            printf("This is huluculu festival year.\n");
            H = true;
        }

        if (LY && M55==0)
            printf("This is bulukulu festival year.\n");

        if (LY==false && H==false)
            printf("This is an ordinary year.\n");

        f=true;
    }
    return 0;
}
