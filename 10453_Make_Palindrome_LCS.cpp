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

void LCS()
{
    memset(T,0,sizeof(T));
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<a.size();j++)
        {
            if(a[i]==b[j])
            {
                T
            }
        }
    }
}
int main()
{
    while(cin>>a)
    {
        b=a;
        reverse(b.begin(),b.end());

        LCS();
        str="";
        find_string();

        cout<<T[a.size()][a.size()]<<" "<<str<<endl;
    }
    return 0;
}
