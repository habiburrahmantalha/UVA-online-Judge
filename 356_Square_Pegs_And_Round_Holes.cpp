//Problem Type :
//Time : .012
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
double dist(double x,double y)
{
    return sqrt(x*x+y*y);
}
int n;
int outside()
{
    double r=double(n)-0.5;
    int i,j,c=0;
    for(i=n-1;i>0 ;i--)
    {
        for(j=n-1;j>0 ;j--)
        {
            if(dist(i,j)>r)
            {
                //cout<<i<<" "<<j<<endl;
                c++;
            }
            else
                break;
        }
    }
    return c;
}
int main()
{
    int line,inside;
    bool f=false;
    while(scanf("%d",&n)==1)
    {
        if(f)
        printf("\n");

        line=((n*2)-1)*4;
        inside=4*n*n-line-outside()*4;
        printf("In the case n = %d, %d cells contain segments of the circle.\n",n,line);
        printf("There are %d cells completely contained in the circle.\n",inside);

        f=true;
    }
    return 0;
}
