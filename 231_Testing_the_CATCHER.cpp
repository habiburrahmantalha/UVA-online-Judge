#include<stdio.h>
#include<vector>

using namespace std;
int mx;
vector<int>v;

void LIS()
{

    vector<int>c(v.size(),0);
    int i,j,m;
    for(i=1;i<v.size();i++)
    {
        m=0;
        for(j=i-1;j>=0;j--)
        {
            if(v[i]<=v[j])
            {
                if(m<c[j])
                m=c[j];
            }
        }
        if(mx<=m)
        mx=m+1;
        c[i]=m+1;

    }
    //for(i=0;i<c.size();i++)
    //printf("%d ",c[i]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    int x,y,t=1;
    bool f=false;
    while(scanf("%d",&x) && x!=-1)
    {
        if(f)
        printf("\n");
        f=true;
        v.push_back(33767);
        v.push_back(x);
        while(scanf("%d",&y) && y!=-1)
        {
            //if(y<=x)
            v.push_back(y);
        }
        mx=0;
        LIS();
        printf("Test #%d:\n",t++);
        printf("  maximum possible interceptions: %d\n",mx);
        v.clear();
    }
    return 0;
}
