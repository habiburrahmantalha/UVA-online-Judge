#include<stdio.h>
#include<string.h>

bool div11(char x[])
{
    int rem=0,len,i;
    len=strlen(x);

    for(i=0;i<len;i++)
        rem=(rem*10+(x[i]-'0'))%11;

    if(rem==0)
    return true;
    else
    return false;
}
int main()
{
    char x[1010];
    while(scanf("%s",x))
    {
        if(strcmp(x,"0")==0)
        break;
        if(div11(x))
        printf("%s is a multiple of 11.\n",x);
        else
        printf("%s is not a multiple of 11.\n",x);
    }
    return 0;
}


