#include<stdio.h>
#include<string.h>

int main()
{
    char ch;
    bool f=false;
    while(1)
    {
        ch=getchar();
        if(ch==EOF)
        break;
        if(ch=='"')
        {
            if(f==false)
            {
                printf("``");
                f=true;
            }
            else
            {
                printf("''");
                f=false;
            }
        }
        else
        printf("%c",ch);

    }
    return 0;
}
