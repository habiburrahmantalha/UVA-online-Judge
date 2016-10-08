#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    int tc,i,n,h;
    string s;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&h);
        s="";
        for(i=0;i<n-h;i++)
        s+="0";
        for(i=0;i<h;i++)
        s+="1";

        do
        {
            cout<<s<<endl;

        }while(next_permutation(s.begin(),s.end()));

        if(tc)
        printf("\n");
    }
    return 0;
}
