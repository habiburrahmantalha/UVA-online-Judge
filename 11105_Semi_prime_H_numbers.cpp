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
bool H[1000011];
set<int> H_semi_S;
vector<int>v,H_semi;
void preca_H()
{
    long long i,j;
    memset(H,false,sizeof(H));
    for(i=1;i<=1000001;i+=4)
        H[i]=true;

    for(i=5;i<=1000001;i+=4)
    {
        for(j=i;i*j<=1000001;j+=4)
        H[i*j]=false;
    }
    for(i=1;i<=1000001;i+=4)
    {
        if(H[i])
        v.push_back(i);
    }
    cout<<v.size()<<endl;
    for(i=1;i<v.size();i++)
    {
        for(j=i;v[i]*v[j]<=1000001 && j<v.size();j++)
        //H_semi.push_back(v[i]*v[j]);
        H_semi_S.insert(v[i]*v[j]);
    }
    //sort(H_semi.begin(),H_semi.end());
    return;
    set<int> ::iterator it;
    for(it=H_semi_S.begin();it!=H_semi_S.end();it++)
    H_semi.push_back(*it);
    //for(i=0;i<100;i++)
    //cout<<H_semi[i]<<endl;


    //cout<<H_semi.size();
}
int main()
{
    preca_H();
    //return 0;
    int n,LW;
    while(scanf("%d",&n) && n)
    {
        //for(int i=0;i<100;i++)
        //cout<<H_semi[i]<<endl;
        LW=int(lower_bound(H_semi.begin(),H_semi.end(),n)-H_semi.begin());
        printf("%d %d\n",n,LW);
    }
    return 0;
}
