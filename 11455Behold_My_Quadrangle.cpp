//don't know rectangle properties :(
#include<stdio.h>

bool rectangle()
{
    if(a==b && c==d)
    return true;
    else if(a==c && b==d)
    return true;
    else if(a==d && b==c)
    return true;
    else
    return false;
}

bool square()
{
    if(a==b && b==c && c==d)
    return true;
    else
    return false;
}

int main()
{
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(square())
        printf("square\n");
        else if(rectangle())
        printf("rectangle\n");
        else if()
    }

}
