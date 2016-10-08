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

vector<int> divs[1010];
int res[1010];
void precal()
{
    int i,j,x,a,b,c;
    for(i=1;i<1001;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(i%j==0)
            {
                divs[i].push_back(i);
                divs[i].push_back(i/j);
            }
        }
    }
    memset(res,0x7F,sizeof(res));
    for(i=1;i<1001;i++)
    {
        for(a=0;a<divs[i].size();a++)
        {
            for(b=a;b<divs[i].size();b++)
            {
                for(c=b;c<divs[i].size();c++)
                {
                    if(divs[i][a]*divs[i][b]*divs[i][c]==i)
                    {
                        x=divs[i][a]*divs[i][b]*2 + divs[i][a]*divs[i][c]*2 + divs[i][b]*divs[i][c]*2;
                        //cout<<x<<" ";
                        res[i]=min(res[i],x);
                    }
                }
            }

        }
    }
}

int main()
{
    precal();
    int tc,x,i,j,n,mn;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);

        printf("%d\n",res[n]);
    }
    return 0;
}
