#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;

vector<int> v,res;

void print()
{
    int c=0,r,i;
    for(i=v.size()-1;i>=0;i--)
    {
        r=v[i]+c;
        if(r>9)
        c=1;
        else
        c=0;

        res.push_back(r%10);
    }
    if(c>0)
    res.push_back(c);
    for(i=res.size()-1;i>=0;i--)
    printf("%d",res[i]);
    printf("\n");
}
int main()
{
    int tc,i,n,a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            v.push_back(a+b);
        }
        print();
        if(tc!=0)
        printf("\n");

        v.clear();
        res.clear();
    }
    return 0;
}
