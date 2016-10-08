//Problem Type : addhoc
//Time :
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
    unsigned long long n,f,x,sum,res,t=1,i;
    while(cin>>n>>f && n && f)
    {
        sum=0;
        for(i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
        }
        res=floor(sum/f);
        cout<<"Bill #"<<t++<<" costs "<<sum<<": each friend should pay "<<res<<endl<<endl;
    }
    return 0;
}
