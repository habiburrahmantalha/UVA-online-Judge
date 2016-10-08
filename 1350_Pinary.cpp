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

void print(int x)
{
    if(x==0)
        return;
    else
    {
        print(x>>1);
        if(x&1)
            cout<<"1";
        else
            cout<<"0";
    }
}

int main()
{
    int tc,x;
    //scanf("%d",&tc);
    //while(tc--)
    for(x=1;x<35;x++)
    {
        //scanf("%d",&x);
        cout<<(1<<x)<<" "<<x<<" ";
        print(x);
        cout<<endl;
    }
    return 0;
}
