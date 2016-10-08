#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<ctype.h>
using namespace std;


int main()
{
    int tc,i,n,mn,x;
    vector<int>g[1010];
    char y[10];
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d",&n);
        getchar();
        for(i=1;i<=n;i++)
        {
            while(scanf("%[0-9]",&y)==1)
            {
                x=atoi(y);
                g[i].push_back(x);
                scanf("%[ ]",&y);
            }
            getchar();
        }
        mn=1110;
        for(i=1;i<=n;i++)
        if(mn>g[i].size())
        mn=g[i].size();


        for(i=1;i<=n;i++)
        {
            if(g[i].size()==mn)
            {
                printf("%d",i);
                break;
            }
        }
        for(i=i+1;i<=n;i++)
        if(g[i].size()==mn)
            printf(" %d",i);
        printf("\n");

        for(i=1;i<=n;i++)
        g[i].clear();
    }
    return 0;
}
