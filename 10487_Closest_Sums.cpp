#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,x[1010],mx;
vector<int>res;
void sum()
{
    res.clear();
    int i,j,k;
    mx=0;
    for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
    if(x[i]!=x[j])
    {
        k=x[i]+x[j];
        res.push_back(k);
    }
    sort(res.begin(),res.end());
}


int main()
{
    int t=1,i,j,m,q,a,b;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        scanf("%d",&x[i]);

        sum();

        scanf("%d",&q);
        printf("Case %d:\n",t++);
        while(q--)
        {
            scanf("%d",&m);
            a=(int) (lower_bound(res.begin(),res.end(),m)-res.begin());
            //b=(int) (upper_bound(res.begin(),res.end(),m)-res.begin());
            //printf("%d %d\n",res[a],res[b]);

            if(a>=res.size())
                printf("Closest sum to %d is %d.\n",m,res[a-1]);
            else
            {
                if(a-5<0)
                i=0;
                else
                i=a-5;
                if(a+5>=res.size())
                j=res.size();
                else
                j=a+5;

                int mn=(1<<30);
                for(;i<j;i++)
                if(mn>abs(m-res[i]))
                {
                    mn=abs(m-res[i]);
                    b=res[i];
                }
                printf("Closest sum to %d is %d.\n",m,b);
            }
        }
    }
    return 0;
}
