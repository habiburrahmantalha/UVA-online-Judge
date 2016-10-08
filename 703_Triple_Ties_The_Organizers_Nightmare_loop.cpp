//Problem Type :
//Time :    TLE
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

bool g[110][110],n;

vector<vector<int> > cycle;

int main()
{
    int i,j,k;
    while(scanf("%d",&n)==1)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                scanf("%d",&g[i][j]);
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {

                for(k=1;k<=n;k++)
                {
                    if( ( (i<j && j<k) || (i>j && j>k) ) && g[i][j] && g[j][k] && g[k][i] )
                    {
                        vector<int> t;
                        t.push_back(i);
                        t.push_back(j);
                        t.push_back(k);

                        cycle.push_back(t);

                    }
                    else if(i<j && j<k && !g[i][j] && !g[j][k] && !g[k][i] && !g[j][i] && !g[k][j] && !g[i][k])
                    {
                        vector<int> t;
                        t.push_back(i);
                        t.push_back(j);
                        t.push_back(k);

                        cycle.push_back(t);
                    }

                }

            }

        }
        printf("%d\n",cycle.size());
        //sort(cycle.begin(),cycle.end());
        for(i=0;i<cycle.size();i++)
            printf("%d %d %d\n",cycle[i][0],cycle[i][1],cycle[i][2]);


        cycle.clear();



    }
    return 0;
}
