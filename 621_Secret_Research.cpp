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
    int tc;
    scanf("%d",&tc);
    string s;
    while(tc--)
    {
        cin>>s;
        if(s=="1" || s=="4" || s=="78")
        printf("+\n");
        else if(s[s.size()-1]=='5' && s[s.size()-2]=='3')
        printf("-\n");
        else if(s[0]=='9' && s[s.size()-1]=='4')
        printf("*\n");
        else if(s[0]=='1' && s[1]=='9' && s[2]=='0')
        printf("?\n");
    }
    return 0;
}
