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
    int tc,i,c,l,t=1;
    string s;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&l);
        cin>>s;
        c=0;
        for(i=0;i<l;i++)
        {
            if(s[i]=='.')
            {
                i+=2;
                c++;
            }

        }
        printf("Case %d: %d\n",t++,c);
    }

    return 0;
}
