#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<int> s;

bool travel()
{
    int i;
    for(i=0;i<s.size()-1;i++)
    {
        if(s[i+1]-s[i]>200)
        return false;
    }
    if(s[s.size()-1]!=1422)
    {
        if((1422-s[s.size()-1])*2>200)
            return false;
    }

    return true;
}

int main()
{

    int x,i;
    while(scanf("%d",&n) && n)
    {
        s.push_back(0);
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x!=0)
            s.push_back(x);
        }
        sort(s.begin(),s.end());
        if(travel())
            printf("POSSIBLE\n");
        else
            printf("IMPOSSIBLE\n");
        s.clear();

    }
    return 0;
}
