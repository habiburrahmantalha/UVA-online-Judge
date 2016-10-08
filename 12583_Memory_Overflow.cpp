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
    int tc,t=1,n,m,i,j,k,cnt;
    char s[510];

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %s",&n,&m,s);
        cnt=0;
        for(i=1;i<n;i++)
        {
            for(j=i-1,k=0;j>=0 && k<m;j--,k++)
            {
                if(s[i]==s[j])
                {
                    cnt++;
                    break;
                }
            }
        }
        printf("Case %d: %d\n",t++,cnt);
    }
    return 0;
}
