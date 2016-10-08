#include<stdio.h>
#include<string.h>

int main()
{
    int tc,m,n,c,d;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&m,&n);
        c=0;
        while(m>=n)
        {
            c+=m/n;
            m=(m/n)+(m%n);
            if(n==1)
            {
                m=1;
                break;
            }
        }

        if(m==1)
        printf("%d\n",c);
        else
        printf("cannot do this\n");
    }
    return 0;
}
