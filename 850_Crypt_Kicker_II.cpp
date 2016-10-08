#include<stdio.h>
#include<string.h>
#include<map>

using namespace std;


int main()
{
    //freopen("in.txt","r",stdin);
    char key[]={"the quick brown fox jumps over the lazy dog"};
    int tc,l,i,j,k;
    char s[110][100];
    bool solution,line=false;
    map<char,char>mkey;
    scanf("%d",&tc);
    getchar();

    while(tc--)
    {
        memset(s,0,sizeof(s));
        if(line)
            printf("\n");
        solution=false;
        l=0;
        while(gets(s[l])!=NULL)
        {
            if(strlen(s[l])==43)
            {
                solution=true;
                k=l;
            }
            l++;
        }
        if(solution)
        {
            for(i=0;i<43;i++)
            {
                mkey[s[k][i]]=key[i];
            }
            for(i=0;i<l;i++)
            {
                for(j=0;s[i][j]!=NULL;j++)
                    printf("%c",mkey[s[i][j]]);
                printf("\n");
            }
        }
        else
            printf("No solution.\n");

    }
    return 0;
}
