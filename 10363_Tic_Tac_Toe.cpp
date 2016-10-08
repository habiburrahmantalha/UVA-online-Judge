#include<stdio.h>
#include<map>

using namespace std;

int main()
{
    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<3;i++)
            scanf("%s",t[i]);
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                mp[t[i][j]]++;
        if(mp['X']<mp['O'] || mp['X']>mp['O']+1)
            printf("no\n");
        else
        {
            if(vertical('X') || horizontal('X') || diagonal('X'))
        }
    }
}
