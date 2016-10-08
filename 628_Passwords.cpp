//Problem Type : Backtracking
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
char x[260];
vector<string> v;
int n;
string tostr(int i)
{
    if(i==0)
    return "0";
    else if(i==1)
    return "1";
    else if(i==2)
    return "2";
    else if(i==3)
    return "3";
    else if(i==4)
    return "4";
    else if(i==5)
    return "5";
    else if(i==6)
    return "6";
    else if(i==7)
    return "7";
    else if(i==8)
    return "8";
    else if(i==9)
    return "9";
}
void password(string s,int i,int k)
{
    int j;
    if(!x[i])
    {
        printf("%s\n",s.c_str());
        return;
    }
    if(x[i]=='#')
    {
        //for(j=0;j<n;j++)
        password(s+v[k],i+1,k);
    }
    else
    {
        for(j=0;j<=9;j++)
            password(s+tostr(j),i+1,k);
    }
}

int main()
{
    int i,m;
    while(scanf("%d",&n)==1)
    {
        printf("--\n");
        for(i=0;i<n;i++)
        {
            scanf("%s",x);
            v.push_back(x);
        }
        scanf("%d",&m);
        while(m--)
        {
            scanf("%s",&x);
            for(i=0;i<n;i++)
            password("",0,i);
        }
        v.clear();
    }

    return 0;
}
