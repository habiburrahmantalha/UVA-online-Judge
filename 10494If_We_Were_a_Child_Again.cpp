//read the problem :P

#include<stdio.h>
#include<string.h>

int main()
{
    long long x,y;
    char ch;
    while(scanf("%lld %c %lld",&x,&ch,&y)==3)
    {
        if(ch=='/')
        printf("%lld\n",x/y);
        else
        printf("%lld\n",x%y);
    }
    return 0;

}
