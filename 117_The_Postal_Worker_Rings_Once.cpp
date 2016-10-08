#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int f[30][3];
void reset()
{
    for(int i=0;i<30;i++)
    {
        f[i][0]=0;
        f[i][1]=0;
    }
}
int main()
{
    int cost=0,l,i;
    char s[10000];
    reset();
    while(scanf("%s",s)==1)
    {
        if(strcmp(s,"deadend")==0)
        {
            for(i=0;i<27;i++)
                if(f[i][0]%2!=0)
                cost+=f[i][1];
                //printf("%c %d %d\n",i+'a',f[i][0],f[i][1]);
            printf("%d\n",cost);
            cost=0;
            reset();
            continue;

        }
        l=strlen(s);
        f[s[0]-'a'][0]++;
        f[s[0]-'a'][1]=max(f[s[0]-'a'][1],l);

        f[s[l-1]-'a'][0]++;
        f[s[l-1]-'a'][1]=max(f[s[l-1]-'a'][1],l);

        cost+=l;
    }
    return 0;
}
