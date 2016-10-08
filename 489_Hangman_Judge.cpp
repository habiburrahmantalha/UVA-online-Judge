#include<stdio.h>
#include<map>
#include<string.h>
using namespace std;

int main()
{
    int n,l,i,count;
    char a[10000];
    map<char,int> mp,mp2;
    while(scanf("%d",&n) && n>=0)
    {
        scanf("%s",a);
        l=strlen(a);
        for(i=0;i<l;i++)
            mp[a[i]]++;
        scanf("%s",a);
        count=0;
        printf("Round %d\n",n);
        for(i=0;i<strlen(a);i++)
        {

            if(mp[a[i]]==0)
                count++;
            else if(mp[a[i]]==-1)
                continue;
            else
            {
                l-=mp[a[i]];
                mp[a[i]]=-1;
            }

            if(l==0)
            {
                printf("You win.\n");
                break;
            }
            if(count>=7)
            {
                printf("You lose.\n");
                break;
            }
        }
        if(count<7 && l!=0)
            printf("You chickened out.\n");
        //printf("%d %d",count,l);
        mp.clear();
    }
    return 0;
}
