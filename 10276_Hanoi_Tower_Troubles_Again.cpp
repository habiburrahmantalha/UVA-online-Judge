//Problem Type :
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

vector<int>v[55];
int a[55];
bool squre(int x)
{
    for(int i=1;i*i<=x;i++)
    {
        if(i*i==x)
            return true;
    }

    return false;
}
void precal()
{
    int c=2,i;
    int n=1;
    memset(a,0,sizeof(a));
    v[1].push_back(1);
    while(n!=51)
    {
        for(i=1;i<=n;i++)
        {
            if(squre(v[i].back()+c))
            {
                v[i].push_back(c);
                break;
            }
        }
        if(i>n)
        {
            for(i=1;i<=n;i++)
            a[n]+=v[i].size();

            v[i].push_back(c);
            n++;
        }
        c++;
    }
}

int main()
{
    precal();
    int tc,n;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
    return 0;
}
