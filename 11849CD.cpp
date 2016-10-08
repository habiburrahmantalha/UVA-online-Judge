#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int n,m,i,count,x;
    while(scanf("%d %d",&n,&m) &&n &&m)
    {
        vector<int> cd;

        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            cd.push_back(x);
        }
        sort(cd.begin(),cd.end());
        count=0;
        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            if (binary_search (cd.begin(), cd.end(), x))
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
