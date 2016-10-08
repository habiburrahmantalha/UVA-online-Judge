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


struct fr
{
    char c;
    int f;
};

bool comp(fr a,fr b)
{
    return a.f>b.f;
}

int main()
{

    int tc,i;

    scanf("%d",&tc);

    while(tc--)
    {
        fr a[131],b[131];
        char key[10000],encode[10000];

        scanf("%s",key);
        scanf("%s",encode);

        for(i=0;i<130;i++)
        a[i].f=b[i].f=0;

        for(i=0;key[i];i++)
        {
            a[key[i]].c=key[i];
            a[key[i]].f++;
        }
        for(i=0;encode[i];i++)
        {
            b[encode[i]].c=encode[i];
            b[encode[i]].f++;
        }
        sort(a,a+130,comp);
        sort(b,b+130,comp);

        map<char,char>m;
        for(i=0; ;i++)
        {
            if(a[i].f==0 && b[i].f==0)
            break;
            m[b[i].c]=a[i].c;
        }


        for(i=0;encode[i];i++)
        printf("%c",m[encode[i]]);;
        printf("\n");

        if(tc)
        printf("\n");
    }
}

