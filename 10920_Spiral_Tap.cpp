//Problem Type :
//Time : 0.328
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

int n,v,p;

void find_position()
{
    int x,i,j,a,b;
    a=(n-p)/2;
    //cout<<a<<" ";
    if(v!=1)
        x=(p-2)*(p-2);
    else
        x=0;
    //cout<<x<<endl;
    for(i=p,j=p-1;j>1;j--)
    {
        x++;
        if(x==v)
        {
            //cout<<"1"<<endl;
            printf("Line = %d, column = %d.\n",i+a,j+a);
            return;
        }

    }
    //cout<<i<<" "<<j<<" "<<x<<endl;
    for(i=p,j=1;i>=1;i--)
    {
        x++;
        if(x==v)
        {
            //cout<<"2"<<endl;
            printf("Line = %d, column = %d.\n",i+a,j+a);
            return;
        }

    }
    //cout<<i<<" "<<j<<" "<<x<<endl;
    for(i=1,j=2;j<p;j++)
    {
        x++;
        if(x==v)
        {
            //cout<<"3"<<endl;
            printf("Line = %d, column = %d.\n",i+a,j+a);
            return;
        }

    }
    //cout<<i<<" "<<j<<" "<<x<<endl;
    for(i=1,j=p;i<=p;i++)
    {
        x++;
        if(x==v)
        {
            //cout<<"4"<<endl;
            printf("Line = %d, column = %d.\n",i+a,j+a);
            return;
        }

    }
    //cout<<i<<" "<<j<<" "<<x<<endl;

}
int main()
{
    while(scanf("%d %d",&n,&v) &&n)
    {
        p=ceil(sqrt(v));
        if(!(p&1))
        p++;

        find_position();
    }
    return 0;
}
