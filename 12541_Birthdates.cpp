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
struct bday
{
    string name;
    int day,month,year;
};

bool cmp(bday a,bday b)
{
    if(a.year==b.year)
    {
        if(a.month==b.month)
        {
            return a.day<b.day;
        }
        return a.month<b.month;
    }
    return a.year<b.year;
}
int main()
{
    int n,i;
    bday x[110];

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
            cin>>x[i].name>>x[i].day>>x[i].month>>x[i].year;
        sort(x,x+n,cmp);

        cout<<x[n-1].name<<endl<<x[0].name<<endl;
    }
    return 0;
}
