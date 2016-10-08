//Problem Type : adhoc
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


int main()
{
    int tc,i,j,k,a,mx,t=1;
    bool f[4][10010];
    vector<int>v[4],res[4];

    scanf("%d",&tc);
    while(tc--)
    {
        memset(f,false,sizeof(f));

        for(i=0;i<3;i++)
        {
            scanf("%d",&k);
            for(j=0;j<k;j++)
            {
                scanf("%d",&a);
                f[i][a]=true;
                v[i].push_back(a);
            }
        }
        for(i=0;i<3;i++)
        {
            for(j=0;j<v[i].size();j++)
            {
                if(!f[(i+1)%3][v[i][j]] && !f[(i+2)%3][v[i][j]])
                res[i].push_back(v[i][j]);
            }
        }
        mx=0;
        for(i=0;i<3;i++)
        {
            if(res[i].size() > mx)
            {
                mx=res[i].size();
            }
        }

        printf("Case #%d:\n",t++);
        for(i=0;i<3;i++)
        {
            if(res[i].size()==mx)
            {
                sort(res[i].begin(),res[i].end());
                printf("%d %d",i+1,res[i].size());
                for(j=0;j<res[i].size();j++)
                printf(" %d",res[i][j]);
                printf("\n");
            }
        }

        for(i=0;i<4;i++)
        {
            v[i].clear();
            res[i].clear();
        }
    }
    return 0;
}
