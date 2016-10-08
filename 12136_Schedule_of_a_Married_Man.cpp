#include<stdio.h>

int main()
{
    //freopen("in.txt","r",stdin);
    int tc,ws,we,ms,me,h1,h2,m1,m2,t=1;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        ws=h1*60+m1;
        we=h2*60+m2;
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        ms=h1*60+m1;
        me=h2*60+m2;
        //printf("%d %d %d %d\n",ws,we,ms,me);
        if((ms>=ws && ms<=we) ||(me>=ws && me<=we))
            printf("Case %d: Mrs Meeting\n",t++);
        else if((ws>=ms && ws<=me) ||(we>=ms && we<=me))
            printf("Case %d: Mrs Meeting\n",t++);
        else
            printf("Case %d: Hits Meeting\n",t++);

    }
    return 0;
}
