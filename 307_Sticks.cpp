#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n,part[55],sum,ans,sticks;
bool visit[55];

bool cmp(int a,int b)
{
    return a>b;
}
bool stick(int L,int S,int K)
{
    if(S==sum/ans)
        return true;
    for(int i=K;i<n;i++)
    {
        if(!visit[i])
        {
            if(L+part[i]==ans)
            {
                visit[i]=true;
                if(stick(0,S+1,0))return true;
                visit[i]=false;
                return false;
            }
            else if(L+part[i]<ans)
            {
                    visit[i]=true;
                    if(stick(L+part[i],S,i+1))return true;
                    visit[i]=false;
                    if(L==0)
                    return false;
                    while(part[i]==part[i+1])i++;
            }

        }
    }
    return false;
}
int main()
{
    int i,mx;
    while(scanf("%d",&n) && n)
    {
        sum=mx=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&part[i]);
            sum+=part[i];
            mx=max(mx,part[i]);
        }

        sort(part,part+n,cmp);
        for(ans=mx;ans<=sum;ans++)
        {
            if(sum%ans==0)
            {
                memset(visit,false,sizeof(visit));
                sticks=sum/ans;
                if(stick(0,0,0))
                break;
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}
