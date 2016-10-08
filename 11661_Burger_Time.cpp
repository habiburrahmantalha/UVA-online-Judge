//Problem Type : add hoc
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
    int i,n,mn;
    char s[2000010];
    queue<int>q;
    while(scanf("%d",&n) && n)
    {
        scanf("%s",s);
        mn=20000000;
        for(i=0;i<n;i++)
        {
            if(s[i]=='Z')
            {
                mn=0;
                break;
            }
            if(s[i]!='.')
            {
                if(q.empty())
                q.push(i);
                else
                {
                    if(s[i]==s[q.front()])
                    {
                        q.pop();
                        q.push(i);
                    }
                    else
                    {
                        if(mn>i-q.front())
                        mn=i-q.front();
                        q.pop();
                        q.push(i);
                    }
                }
            }
        }

        printf("%d\n",mn);
        while(!q.empty())
        q.pop();
    }
    return 0;
}
