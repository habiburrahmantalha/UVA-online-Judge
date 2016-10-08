#include<stdio.h>
#include<vector>
#include<string.h>

using namespace std;

vector<int> v;
int n;
void reset()
{
    v.clear();
    for(int i=1;i<=n*2;i++)
    v.push_back(i);
}

bool bad_killed(int m)
{
    reset();
    int in=m;

    while(1)
    {
        if(in<=n)
        return false;

        if(v.size()==n)
        return true;

        v.erase(v.begin()+n);
        //in+=(m%v.size());
        //if(in>v.size())
        //in%=v.size();
    }

}


int main()
{
    int i;

    while(scanf("%d",&n) && n)
    {
        for(i=n; ; i++)
        {
            if(bad_killed(i))
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
