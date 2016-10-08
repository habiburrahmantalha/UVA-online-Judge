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
#include<stack>
using namespace std;
#define PI 2 * acos (0.0)


int main()
{
    int tc,t=1,i,f[140];
    char s[10010];
    stack<char>st;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",s);
        memset(f,0,sizeof(f));
        st.push(s[0]);
        for(i=1;s[i];i++)
        {
            if(st.top()==s[i])
            {
                st.pop();
            }
            else
            {
                f[st.top()]++;
                f[s[i]]++;
                st.push(s[i]);

            }

        }
        printf("Case %d\n",t++);
        for(i=0;i<130;i++)
        {
            if(f[i])
            printf("%c = %d\n",i,f[i]);
        }
    }
    return 0;
}
