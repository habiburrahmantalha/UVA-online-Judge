#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    /*
    long long i,j;
    for(i=0;i<10000;i++)
    {
        for(j=0;j<10000;j++)
        {
            if((i+j)*(i+j)==(i*10000+j))
                printf("%lld %lld\n",i,j);
        }
    }
    */
    int n;
    while(cin>>n)
    {
        if(n==2)
            printf("00\n01\n81\n");
   		else if(n==4)
            printf("0000\n0001\n2025\n3025\n9801\n");
   		else if(n==6)
            printf("000000\n000001\n088209\n494209\n998001\n");
   		else if(n==8)
            printf("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n");
    }
    return 0;
}
