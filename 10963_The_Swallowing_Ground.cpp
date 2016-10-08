#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;


int main()
{
    int tc,y,y1,y2,n;
    bool f;
    scanf("%d",&tc);
    while(tc--)
    {

        scanf("%d",&n);
        f=true;
        scanf("%d %d",&y2,&y1);
        y=y2-y1;
        n--;
        while(n--)
        {
            scanf("%d %d",&y2,&y1);
            if(y!=(y2-y1))
            f=false;

        }
        if(f)
        printf("yes\n");
        else
        printf("no\n");
        if(tc)
        printf("\n");
    }
    return 0;
}
