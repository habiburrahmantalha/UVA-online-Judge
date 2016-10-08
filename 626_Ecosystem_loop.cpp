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
/*
map<vector<int>,int>v;
vector<vector<int> > cycle;
bool sorted(vector<int> t)
{
    if((t[0]> t[1] && t[1]>t[2]) || (t[0]< t[1] && t[1]<t[2]) )
    return true;
    return false;
}
*/
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
    int c=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {

                for(k=1;k<=n;k++)
                {
                    if( ( (i<j && j<k) || (i>j && j>k) ) && g[i][j] && g[j][k] && g[k][i] )
                    {
                        printf("%d %d %d\n",i,j,k);
                        /*
                        vector<int> t;
                        t.push_back(i);
                        t.push_back(j);
                        t.push_back(k);
                        while(!sorted(t))
                        rotate(t.begin(),t.begin()+1,t.end());
                        if(v[t]==0)
                        {
                            v[t]=1;
                            cycle.push_back(t);
                        }
                        */
                        c++;
                    }

                }

            }

        }
        /*
        sort(cycle.begin(),cycle.end());
        for(i=0;i<cycle.size();i++)
            printf("%d %d %d\n",cycle[i][0],cycle[i][1],cycle[i][2]);
        printf("total:%d\n",cycle.size());
        printf("\n");
        cycle.clear();
        v.clear();
        */
        printf("total:%d\n",c);

    }
    return 0;
}
