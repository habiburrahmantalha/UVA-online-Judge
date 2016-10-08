#include<stdio.h>
#include<ctype.h>
int main()
{
    int c;
    char s[100],ch;
    bool f;

    while(scanf("%s",s))
    {
        f=true;
        if(s[0]=='*')
            break;
        ch=tolower(s[0]);
        scanf("%[ ]",s);
        while(scanf("%[A-Za-z]",s))
        {
            if(tolower(s[0])!=ch)
                f=false;
            while(scanf("%[ ]",s))
                c=0;
        }
        if(f)
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}
