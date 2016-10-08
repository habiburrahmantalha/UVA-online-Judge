#include<stdio.h>

int main()
{
    int q,a,b,x,y;
    while(scanf("%d",&q) && q)
    {
        scanf("%d %d",&a,&b);
        while(q--)
        {
            scanf("%d %d",&x,&y);
            if(a==x || b==y)
                printf("divisa\n");
            else if(x>a && y>b)
                printf("NE\n");
            else if(x<a && y<b)
                printf("SO\n");
            else if(x>a && y<b)
                printf("SE\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
