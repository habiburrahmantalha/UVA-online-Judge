#include<stdio.h>

int main()
{
    int h1,h2,m1,m2,time;
    while(scanf("%d %d %d %d",&h1,&m1,&h2,&m2))
    {
        if(h1==0 && h2==0 && m1==0 && m2==0)
        break;
        time=0;
        if(h1==h2 && m2>m1)
        time=m2-m1;
        else
        {
            time+=((60-m1)+m2);
            h1++;
            if(h1==24)
            h1=0;
            if(h1!=h2)
            {
                if(h1<h2)
                time+=((h2-h1)*60);
                else
                time+=(((24-h1)+h2)*60);
            }
        }
        printf("%d\n",time);

    }
    return 0;
}
