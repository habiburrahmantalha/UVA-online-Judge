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

char birth_day_song[20][9]={"Happy",
                            "birthday",
                            "to",
                            "you",
                            "Happy",
                            "birthday",
                            "to",
                            "you",
                            "Happy",
                            "birthday",
                            "to",
                            "Rujia",
                            "Happy",
                            "birthday",
                            "to",
                            "you"
                            };

int main()
{
    char people[110][100];
    int p,s,i,n;
    bool all_sing;
    while(scanf("%d",&n)==1)
    {
        all_sing=false;
        for(i=0;i<n;i++)
            scanf("%s",&people[i]);
        p=s=0;
        while(true)
        {
            printf("%s: %s\n",people[p],birth_day_song[s]);

            if(all_sing && s==15)
            break;

            if(p==n-1)
            all_sing=true;
            p=(p+1)%n;
            s=(s+1)%16;
        }
    }
    return 0;
}
