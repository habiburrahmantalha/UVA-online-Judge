#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int x,int y)
{
    return x>y;
}
int t,n,a[1010],x[1010];
vector< vector<int> > v;
void backtrack(int sum,int j,int k)
{
    int i,l;
    //printf("%d",a[j]);
    if(sum>t)
        return ;

    x[k]=a[j];
    k++;
    if(sum==t)
    {
        sort(x,x+k,comp);
        vector<int> y(x,x+k);
        for(l=0;l<v.size();l++)
            if(v[l]==y)
                return;
        v.push_back(y);
        //return;
        //for(l=0;l<k;l++)
            //printf("%d ",x[l]);
        //printf("\n");
        return;
    }
    for(i=j+1;i<n;i++)
    {
        if(sum+a[i]<=t)
        {
            //printf("%d",sum);
            x[k]=a[i];
            backtrack(sum+a[i],i,k);
        }

    }
}

int main()
{
    int i,j;
    while(scanf("%d %d",&t,&n))
    {
        if(t==0 && n==0)
            break;

        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
        backtrack(a[i],i,0);

        printf("Sums of %d:\n",t);
        if(v.size()==0)
            printf("NONE\n");
        else
        {
            sort(v.begin(),v.end());
            for(i=v.size()-1;i>=0;i--)
            {
                for(j=0;j<v[i].size()-1;j++)
                    printf("%d+",v[i][j]);
                printf("%d\n",v[i][j]);

            }
        }
        v.clear();
    }
    return 0;
}
