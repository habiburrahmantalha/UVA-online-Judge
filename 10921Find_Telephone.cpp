#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    char c[32];
    int i,len;
    char x[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    int y[]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
    while(scanf("%s",c)==1)
    {
        len=strlen(c);
        for(i=0;i<len;i++)
        {
            if(isalpha(c[i]))
            printf("%d",y[c[i]-'A']);
            else
            printf("%c",c[i]);
        }
        printf("\n");

    }
    return 0;
}
