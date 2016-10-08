#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char M[1000],ch;
    int in,n,i;
    in=n=0;
    while(1)
    {

        ch==getchar();
        printf("%c",ch);
        if(isdigit(ch))
        n+=ch-'0';
        else if(isupper(ch))
        {
            for(i=0;i<n;i++)
            M[in++]=ch;
            n=0;

        }
        else if(ch=='b')
        {
            M[in++]=' ';
        }
        else if(ch=='\n' ||ch=='!')
        {
            M[in++]='\n';
        }
        else
        break;
    }
    printf("%s",M);
}
