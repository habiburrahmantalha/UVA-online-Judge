#include<stdio.h>
#include<stdlib.h>
int main()
{
    char x[100];
    int n,i,p[1010],c[1010];
    while(scanf("%[A-Za-z= ]",x)==1)
    {
        scanf("%[0-9]",x);
        n=atoi(x);
        getchar();
        for(i=0;i<n;i++)
        {
            scanf("%[A-Za-z= ]",x);
            scanf("%[0-9]",x);
            p[i]=atoi(x);
            getchar();

        }
        for(i=0;i<n-1;i++)
        {
            scanf("%[A-Za-z= ]",x);
            scanf("%[0-9]",x);
            c[i]=atoi(x);
            getchar();

        }


        //printf("%d",atoi(x));
    }
    return 0;
}
