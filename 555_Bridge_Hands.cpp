#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
using namespace std;

struct card
{
    char c;
    int n;
};

int get_dir(char x)
{
    if(x=='N')
    return 2;
    else if(x=='E')
    return 3;
    else if(x=='S')
    return 0;
    else if(x=='W')
    return 1;
}
int getp(char x)
{
    if(x=='C')
    return 0;
    else if(x=='D')
    return 1;
    else if(x=='S')
    return 2;
    else if(x=='H')
    return 3;
}
bool cmp(card a,card b)
{
    if(getp(a.c)==getp(b.c))
        return a.n<b.n;
    else
    return getp(a.c)<getp(b.c);
}
int main()
{
    int n,i,j;
    card z;
    vector<card>p[5];
    string s,str;
    char q[]="SWNE";
    while(cin>>s && s!="#")
    {
        n=get_dir(s[0]);
        n=(n+1)%4;
        for(j=0;j<2;j++)
        {
            cin>>str;
            for(i=0;i<str.size();i+=2)
            {
                z.c=str[i];
                if(str[i+1]=='A')
                z.n=14;
                else if(str[i+1]=='T')
                z.n=10;
                else if(str[i+1]=='J')
                z.n=11;
                else if(str[i+1]=='Q')
                z.n=12;
                else if(str[i+1]=='K')
                z.n=13;
                else
                z.n=str[i+1]-'0';

                //printf("%d%c ",n,z.c);
                p[n].push_back(z);
                n=(n+1)%4;
            }
        }
        for(i=0;i<4;i++)
        /*
        {
            for(j=0;j<13;j++)
            printf("%c ",p[i][j].c);
            printf("\n");
        }
        */
        sort(p[i].begin(),p[i].end(),cmp);

        for(j=0;j<4;j++)
        {
            printf("%c:",q[j]);

            for(i=0;i<13;i++)
            {
                printf(" %c",p[j][i].c);
                if(p[j][i].n==10)
                printf("T");
                else if(p[j][i].n==11)
                printf("J");
                else if(p[j][i].n==12)
                printf("Q");
                else if(p[j][i].n==13)
                printf("K");
                else if(p[j][i].n==14)
                printf("A");
                else
                printf("%d",p[j][i].n);
            }
            printf("\n");
        }

        for(i=0;i<4;i++)
        p[i].clear();
    }

    return 0;
}
