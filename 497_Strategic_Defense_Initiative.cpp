//.088
#include<stdio.h>
#include<string.h>
#include<sstream>
#include<vector>
using namespace std;
int mx,n;
vector<int>v;
int t[1000001];

void subsequence(int x)
{
    if(t[x]==0)
    {
        printf("%d\n",v[x]);
        return;
    }
    else
    {
        subsequence(t[x]);
        printf("%d\n",v[x]);
    }
}


void LIS()
{
    vector<int>c(v.size(),0);
    memset(t,0,sizeof(t));
    int i,j,m,k,mxk;
    for(i=1;i<v.size();i++)
    {
        m=k=0;
        for(j=i-1;j>=0;j--)
        {
            if(v[i]>v[j])
            {
                if(m<c[j])
                {
                    m=c[j];
                    k=j;
                }
            }
        }
        //printf("*%d ",m);
        if(mx<m+1)
        {
            mx=m+1;
            mxk=i;
        }
        c[i]=m+1;
        t[i]=k;
    }
    //for(int i=1;i<v.size();i++)
        //printf("%d  ",c[i]);
    printf("Max hits: %d\n",mx);
    subsequence(mxk);

}


int main()
{
    int tc,a;
    char x[10];
    bool f=false;
    scanf("%d",&tc);
    gets(x);
    gets(x);
    while(tc--)
    {
        if(f)
        printf("\n");
        f=true;
        v.push_back(0);
        while(gets(x))

        {
            if(strlen(x)==0)
            break;
            sscanf(x,"%d",&a);
            v.push_back(a);
        }

        mx=0;
        LIS();

        //for(int i=1;i<v.size();i++)
        //printf("%d ",t[i]);

        v.clear();

    }
    return 0;
}
