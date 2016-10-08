#include<stdio.h>
#include<string.h>

bool div11(char x[])
{
    int rem=0,len,i;
    len=strlen(x);

    for(i=0;i<len;i++)
        rem=(rem*10+(x[i]-'0'))%17;

    if(rem==0)
    return true;
    else
    return false;
}
int main()
{
    char x[10100];
    while(scanf("%s",x))
    {
        if(strcmp(x,"0")==0)
        break;
        if(div11(x))
        printf("1\n");
        else
        printf("0\n");
    }
    return 0;
}


