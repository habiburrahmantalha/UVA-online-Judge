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
    int t;
    while(scanf("%d",&t)==1)
    {
        if(t%6==0)
        printf("Y\n");
        else
        printf("N\n");
    }
    return 0;
}
