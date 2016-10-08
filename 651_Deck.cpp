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

double deck[100000];

void precal()
{

    deck[1]=.500;
    for(int i=2;i<100000;i++)
    {
        deck[i]=deck[i-1]+0.5/(double)i;
    }
}

int main()
{
    precal();
    int n;
    printf("# Cards Overhang\n");
    while(scanf("%d",&n)==1)
    {
        printf("%5d%10.3lf\n",n,deck[n]);

    }
    return 0;
}
