#include<stdio.h>


int x1,x2,y1,y2;

bool check()
{
    int a,b,c,d;
    a=x1;
    b=y1;
    c=x2;
    d=y2;
    while(a<=8 && b>0)
    {
        if(a==c && b==d)
        return true;
        a++;
        b--;
    }
    a=x1;
    b=y1;
    c=x2;
    d=y2;
    while(b<=8 && a
          >0)
    {
        if(a==c && b==d)
        return true;
        a--;
        b++;
    }
    return false;
}
bool in_line()
{
    if(x1==x2 || y1==y2)
    return true;
    else if(x2-x1==y2-y1)
    return true;
    else if(x1-x2==y1-y2)
    return true;
    else if(check())
    return true;
    else
    return false;
}

int main()
{
    while(scanf("%d %d %d %d",&x1,&y1,&x2,&y2))
    {
        if(x1==0 && x2==0 && y1==0 && y2==0)
        break;
        if(x1==x2 && y1==y2)
        printf("0\n");
        else if(in_line())
        printf("1\n");
        else
        printf("2\n");
    }
    return 0;
}
