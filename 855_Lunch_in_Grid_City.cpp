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
    int tc,s,a,f,S[50010],A[50010],i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&s,&a,&f);
        for(i=0;i<f;i++)
        scanf("%d %d",&S[i],&A[i]);

        sort(S,S+f);
        sort(A,A+f);
        if(f&1)
            printf("(Street: %d, Avenue: %d)\n",S[(f-1)/2],A[(f-1)/2]);
        else
            printf("(Street: %d, Avenue: %d)\n",S[(f/2)-1],A[(f/2)-1]);

    }
    return 0;
}
