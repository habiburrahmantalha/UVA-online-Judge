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
int p[110],n;
bool check()
{
    for(int i=0;i<n;i++)
    {
        if(p[i]==i)
            return false;
    }
    return true;
}

int main()
{
    int i,cnt;
    while(scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        p[i]=i;
        cnt=0;
        do
        {
                if(check())
                    cnt++;

        }while(next_permutation(p,p+n));
        cout<<cnt<<endl;
    }

    return 0;
}
