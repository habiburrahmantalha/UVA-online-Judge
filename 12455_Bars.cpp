//Problem Type : Coin Change
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
int n,m,p[25];


bool possible()
{
    bool T[1010];
    int i,j;
    memset(T,false,sizeof(T));
    T[0]=true;
    for(i=0;i<m;i++)
    {
        for(j=n-p[i];j>=0;j--)
            if(T[j])
                T[j+p[i]]=true;
    }
    if(T[n])
    return true;
    else
    return false;
}
int main()
{
    int tc,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        scanf("%d",&p[i]);

        if(possible())
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
