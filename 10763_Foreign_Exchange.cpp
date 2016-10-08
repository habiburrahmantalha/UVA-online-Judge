#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct s_e
{
    int s;
    int e;
};

bool comp(s_e a,s_e b)
{
    if(a.s==b.s)
        return a.e<b.e;
    return a.s<b.s;
}


int main()
{
    vector<s_e>v;
    vector<int>vs;
    vector<int> :: iterator low;
    s_e x;
    int n,i,j,l;
    bool f;
    while(scanf("%d",&n) && n)
    {
        vector<int>visit(n,0);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x.s,&x.e);
            v.push_back(x);

        }
        sort(v.begin(),v.end(),comp);
        for(i=0;i<n;i++)
            vs.push_back(v[i].s);

        for(i=0;i<n;i++)
        {
            low=lower_bound(vs.begin(),vs.end(),v[i].e);
            l=int(low-vs.begin());
            j=0;
            if(v[i].e==v[l].s)
            {
                f=false;
                while(v[i].e==v[l+j].s )
                {
                    if(v[i].s==v[l+j].e && visit[l+j]==0)
                    {
                        f=true;
                        visit[l+j]=1;
                        break;
                    }
                    j++;
                }
            }
            else
            {
                f=false;
            }
            if(f==false)
                break;
        }

        if(f==false)
            printf("NO\n");
        else
            printf("YES\n");
        v.clear();
        vs.clear();
    }
    return 0;
}
