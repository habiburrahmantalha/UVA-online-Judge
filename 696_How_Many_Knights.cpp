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

int solve(int x,int y)
{
    int a,b;
    if(x>y)
    swap(x,y);
    a=floor(y/4);
    b=y%4;
    if(b==0)
    return a*4;
    else if(b==1)
    return a*4+2;
    else if(b>=2)
    return a*4+4;



}
int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y) && x+y)
    {
        if(x==1 || y==1)
        printf("%d knights may be placed on a %d row %d column board.\n",max(x,y),x,y);
        else if(x==2 || y==2)
        printf("%d knights may be placed on a %d row %d column board.\n",solve(x,y),x,y);
        else
        printf("%d knights may be placed on a %d row %d column board.\n",(x*y+1)/2,x,y);

    }
    return 0;
}
