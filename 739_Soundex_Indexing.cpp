#include<stdio.h>
#include<string>
#include<string.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    int i,j,p,len,C[]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
    char name[25];
    printf("         NAME                     SOUNDEX CODE\n");
    while(scanf("%s",&name)==1)
    {
        len=strlen(name);
        p=C[name[0]-'A'];

        printf("         %s",name);
        for(i=10+len;i<35;i++)
        printf(" ");
        printf("%c",name[0]);
        i=1;
        for(j=1;j<len;j++)
        {
            if(i==4)
                break;
            if(C[name[j]-'A']==0 || C[name[j]-'A']==p)
                p=C[name[j]-'A'];
            else
            {
                printf("%d",C[name[j]-'A']);
                p=C[name[j]-'A'];
                i++;
            }
        }
        for(;i<4;i++)
            printf("0");
        printf("\n");
    }
    printf("                   END OF OUTPUT\n");
    return 0;
}
