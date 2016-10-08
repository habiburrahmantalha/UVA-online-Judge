//Problem Type :
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

struct  beads
{
    char c;
    int i;
};
bool cmp(beads a,beads b)
{
    if(a.c==b.c)
        return a.i<b.i;
    return a.c<b.c;

}
int main()
{
    beads x[10010];
    char str[10010];
    int tc,len,i;
    scanf("%d",&tc);
    while(tc--)
    {
        beads x[10010];
        scanf("%s",&str);
        len=strlen(str);
        for(i=0;str[i];i++)
        {
            x[i].c=str[i];
            x[i].i=i+1;
        }
        sort(x,x+len,cmp);
        for(i=0;i<len;i++)
        printf("%c %d\n",x[i].c,x[i].i);

    }
    return 0;
}
