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
    int n,i,q;
    map<string,string>M;
    string str1,str2;

    while(scanf("%d\n",&n)==1)
    {
        for(i=0;i<n;i++)
        {
            getline(cin,str1);
            getline(cin,str2);
            M[str1]=str2;
        }
        scanf("%d\n",&q);
        while(q--)
        {
            getline(cin,str1);
            cout<<M[str1]<<endl;;

        }
        M.clear();
    }
    return 0;
}
