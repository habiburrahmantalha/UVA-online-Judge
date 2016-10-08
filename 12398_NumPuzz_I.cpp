//Problem Type : Add Hoc
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
    int t=1,i,x,g[30],l;
    char s[210];

    while(gets(s))
    {
        memset(g,0,sizeof(g));
        l=strlen(s);
        for(i=0;i<l;i++)
        {
            x=s[i]-'a';
            if(x<3)
            x+=6;
            else if(x<6)
            x+=8;
            else if(x<9)
            x+=10;
            else continue;

            //cout<<x<<endl;
            g[x]=(g[x]+1)%10;
            g[x+1]=(g[x+1]+1)%10;
            g[x-1]=(g[x-1]+1)%10;
            g[x+5]=(g[x+5]+1)%10;
            g[x-5]=(g[x-5]+1)%10;
        }
        printf("Case #%d:\n",t++);
        printf("%d %d %d\n",g[6],g[7],g[8]);
        printf("%d %d %d\n",g[11],g[12],g[13]);
        printf("%d %d %d\n",g[16],g[17],g[18]);
    }
    return 0;
}
