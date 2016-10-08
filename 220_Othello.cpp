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


char g[10][10];
void list_move(int p)
{

}
void move(int p,int x,int y)
{

}
void print()
{
    int i,j;
    for(i=0;i<=8;i++)
    {
        for(j=0;j<=8;j++)
            printf("%c",g[i][j]);
        printf("\n");
    }
}
int main()
{
    int tc,i,j,p;
    string s;
    scanf("%d",&tc);
    while(tc--)
    {
        memset(g,' ',sizeof(g));
        for(i=1;i<=8;i++)
        scanf("%s",g[i]+1);

        print();

        cin>>s;

        if(s=="W")
        p=0;
        if(s=="B")
        p=1;

        while(cin>>s && s!="Q")
        {

            if(s=="L")
                list_move(p);
            if(s[0]=='M')
                move(p,s[1]-'0',s[2]-'0');


        }

    }
    return 0;
}
