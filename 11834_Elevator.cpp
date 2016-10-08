#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    int a,b,c,R1,R2,L,C;
    while(scanf("%d %d %d %d",&L,&C,&R1,&R2) && L+C+R1+R2)
    {
        a=max(R1,R2);
        b=2*a;
        c=2*(R1+R2);

        if(b<=L && c<=C)
        printf("S\n");
        else if(b<=C && c<=L)
        printf("S\n");
        else
        printf("N\n");
    }

    return 0;
}
