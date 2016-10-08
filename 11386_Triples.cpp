#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;

int main()
{
    int n,x[5010],c,i,j;
    map<int,int> mp;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
            mp[x[i]]=1;
        }
        c=0;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            if(mp[x[i]+x[j]]==1)
            c++;
        }
        printf("%d\n",c);
        mp.clear();
    }
    return 0;
}
