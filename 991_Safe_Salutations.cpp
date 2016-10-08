#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

double c[20];
void precal()
{
    c[0]=1;
    for(int i=0;i<11;i++)
    c[i+1]=(((4*i)+2)*c[i])/(i+2);
}
int main()
{
    precal();
    int n;
    bool f=false;
    while(scanf("%d",&n)==1)
    {
        if(f)
        printf("\n");
        f=true;
        printf("%.0lf\n",c[n]);
    }
    return 0;
}
