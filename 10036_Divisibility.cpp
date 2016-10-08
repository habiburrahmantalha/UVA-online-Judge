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
int a[10010],n,k;

bool divisibility()
{
    map<int,int>m;
    map<int,int> :: iterator  it;
    int x,i;

    m[a[0]%k]=0;
    for(i=1;i<n;i++)
    {
        for(it=m.begin();it!=m.end();it++)
        {
            if(it->second==i-1)
            {
                x=it->first;
                //cout<<x<<endl;
                m[(x+a[i]%k)%k]=i;
                m[(x-a[i]%k)%k]=i;
            }
        }
        //cout<<endl;
    }
    for(it=m.begin();it!=m.end();it++)
    {
        //cout<<it->first<<endl;
        if(it->second==n-1 && it->first==0)
        return true;
    }
    return false;


}

int main()
{

    int tc,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&k);
        for(i=0;i<n;i++)
        scanf("%d",&a[i]);

        if(divisibility())
            printf("Divisible\n");
        else
            printf("Not divisible\n");
    }
    return 0;
}
