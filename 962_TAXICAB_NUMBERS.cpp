#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

#define LL long long
#include<map>

map<LL,int> cubeM,T,C;
vector<LL> cubeV;
map<LL,int> ::iterator it;
void precal()
{
    LL i,j;
    for(i=1;i<=1111;i++)
    {
        j=i*i*i;
        cubeM[j]=1;
        cubeV.push_back(j);
    }
}

void coin_change()
{
    T[0]=1;
    C[0]=0;
    LL i,x;
    for(i=0;i<cubeV.size();i++)
    {
        for(it=T.begin();it!=T.end() && (*it).first+cubeV[i]<=1000000000+100000;it++)
        {
            if((*it).second>=1)
            {
                if(C[(*it).first]+1<=2)
                {
                    T[(*it).first+cubeV[i]]++;
                    C[(*it).first+cubeV[i]]=C[(*it).first]+1;
                }

            }
        }
    }
}
bool texicab(LL x)
{
    LL i,c=0,y;
    for(i=0;cubeV[i]<=x;i++)
    {
        y=x-cubeV[i];
        if(cubeV[i] <= y)
        {
            if(cubeM[y])
            //cout<<cubeV[i]<<endl;
            c++;
            if(c==2)
             return true;
        }
        else
            break;
    }
    return false;
}
int main()
{
    precal();
    coin_change();
    freopen("out.txt","w",stdout);

    LL n1,rg,i;
    //texicab(1729);
    /*
    while(scanf("%lld",&n1)==1)
    {
        scanf("%lld",&rg);

        for(i=1;i<=n1+rg;i++)
        if(texicab(i))
        printf("%lld,",i);
    }
    */
    for(it=T.begin();it!=T.end();it++)
    if((*it).second>=2)
    cout<<(*it).first<<",";;
    return 0;
}
