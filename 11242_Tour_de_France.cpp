//Problem Type :
//Time :    0.008
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


int main()
{
    vector<double>v;
    double mx,d,a[110],b[110];
    int i,j,f,r;
    while(scanf("%d",&f) && f)
    {
        scanf("%d",&r);
        for(i=0;i<f;i++)
        scanf("%lf",&a[i]);

        for(i=0;i<r;i++)
        scanf("%lf",&b[i]);

        for(i=0;i<f;i++)
        {
            for(j=0;j<r;j++)
            {
                v.push_back(b[j]/a[i]);
            }
        }
        sort(v.begin(),v.end());
        mx=0;
        for(i=0;i<v.size()-1;i++)
        {
            d=v[i+1]/v[i];
            if(d>mx)
            mx=d;
        }
        printf("%.2lf\n",mx);
        v.clear();

    }
    return 0;
}
