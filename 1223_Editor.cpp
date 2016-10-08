//Problem Type : LCSubstring
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

char str[5010];
int len;
int T[5010][5010];
int LCS()
{
    //memset(T,0,sizeof(T));
    int i,j,mx=0;
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            if(str[i]==str[j] && i!=j)
            {
                if(i==0 || j==0)
                T[i][j]=1;
                else
                mx=max(mx,T[i][j]=T[i-1][j-1]+1);
            }
            else
                T[i][j]=0;
        }
    }
    return mx;

}

int main()
{
    int tc,i;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%s",str);
        len=strlen(str);
        printf("%d\n",LCS());
    }
    return 0;
}
