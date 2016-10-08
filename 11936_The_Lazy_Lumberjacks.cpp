#include<stdio.h>

int a,b,c;

bool triangle()
{
    if(a+b<=c)
        return false;
    else if(a+c<=b)
        return false;
    else if(b+c<=a)
        return false;
    else
        return true;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d",&a,&b,&c);

        if(triangle())
            printf("OK\n");
        else
            printf("Wrong!!\n");
    }
    return 0;
}
