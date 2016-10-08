#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
    int n,m,l,u;
    int i,res;
    vector<int>v;
    while(scanf("%d %d %d",&n,&l,&u)==3)
    {
        m=n;
        i=0;
        while(m)
        {
            if(m&1)
            printf("1");
            else
            printf("0");

            if(!(m&1))
            v.push_back(i);
            i++;
            m>>=1;

        }
        res=0;
        for(i=0;i<v.size();i++)
        {
            m=1;
            m<<=v[i];
            //if(m>=l && m<=u)
            res|=m;
        }
        printf("%d",res);
    }
}
