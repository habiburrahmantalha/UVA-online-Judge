//Problem Type :
//Time :
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

int A,B,C;
vector<int>d;
void div_B()
{
    bool f[10010];
    int i,j,x;
    memset(f,false,sizeof(f));
    for(i=1;i*i<=B;i++)
    {
        if(B%i==0)
        {
            f[i]=true;
            x=B/i;
            f[x]=true;
            for(j=1;j*j<=x;j++)
            {
                if(x%j==0)
                {
                    f[j]=true;
                    f[x/j]=true;
                }
            }
        }
    }
    d.clear();
    for(i=0;i<=B;i++)
        if(f[i])
        {
            //printf("%d ",i);
            d.push_back(i);
            d.push_back(-i);
        }
    //d.push_back(0);
    sort(d.begin(),d.end());
}

int main()
{
    int tc,i,j,k;
    vector<vector<int> >res;
    vector<int>t;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&A,&B,&C);

        div_B();
        for(i=0;i<d.size();i++)
        {
            for(j=0;j<d.size();j++)
            {
                for(k=0;k<d.size();k++)
                {
                    if(d[i]*d[j]*d[k]==B && d[i]+d[j]+d[k]==A && d[i]*d[i]+d[j]*d[j]+d[k]*d[k]==C && d[i]!=d[j] && d[j]!=d[k] &&d[k]!=d[i])
                    {
                        t.clear();
                        t.push_back(d[i]);
                        t.push_back(d[j]);
                        t.push_back(d[k]);

                        res.push_back(t);
                        //printf("%d %d %d\n",d[i],d[j],d[k]);
                    }

                }
            }
        }
        sort(res.begin(),res.end());
        if(res.size()==0)
            printf("No solution.\n");
        else
        {

            printf("%d %d %d\n",res[0][0],res[0][1],res[0][2]);
        }
        res.clear();

    }
    return 0;
}
