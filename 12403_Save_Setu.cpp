#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    int tc;
    string s;
    int x=0,y;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>s;
        if(s=="donate")
        {
            scanf("%d",&y);
            x+=y;
        }
        else
        printf("%d\n",x);
    }
    return 0;
}
