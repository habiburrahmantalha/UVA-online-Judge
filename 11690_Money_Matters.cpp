#include<stdio.h>
#define FOR(i,x,y) for(i=x;i<y;i++)
#define GI(x) scanf("%d",&x)
#include<vector>
#include<algorithm>
using namespace std;
int n,P[10010];

void reset()
{
    int i;
    FOR(i,0,n)
    P[i]=i;
}

int findset(int x)
{
    if(x!=P[x])
        P[x]=findset(P[x]);
    return P[x];
}

void unionset(int x ,int y)
{
    int px=findset(x);
    int py=findset(y);
    P[py]=P[px];
}

int main()
{
    int tc,i,j,a,b,m,x[10010];
    vector<int>owed,owes;
    bool impossible;

    GI(tc);
    while(tc--)
    {

        GI(n);
        GI(m);
        reset();
        FOR(i,0,n)
        {
            GI(x[i]);
            if(x[i]>0)
                owes.push_back(i);
            else
                owed.push_back(i);
        }
        FOR(i,0,m)
        {
            GI(a);
            GI(b);
            unionset(a,b);
        }
        impossible=false;
        FOR(i,0,owes.size())
        {
            FOR(j,0,owed.size())
            {
                if(x[owed[j]]<0)
                {
                    if(findset(owes[i])==findset(owed[j]))
                    {

                        if(x[owes[i]]>abs(x[owed[j]]))
                        {
                            x[owes[i]]+=x[owed[j]];
                            x[owed[j]]=0;
                        }
                        else if(x[owes[i]]<abs(x[owed[j]]))
                        {
                            x[owed[j]]+=x[owes[i]];
                            x[owes[i]]=0;
                            break;
                        }
                        else
                        {
                            x[owes[i]]=x[owed[j]]=0;
                            break;
                        }
                    }
                }
            }
            if(x[owes[i]]!=0)
            {
                impossible=true;
                break;
            }
        }
        if(!impossible)
            FOR(i,0,owed.size())
            if(x[owed[i]]!=0)
            {
                impossible=true;
                break;
            }
        if(impossible)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
        owes.clear();
        owed.clear();

    }
    return 0;
}
