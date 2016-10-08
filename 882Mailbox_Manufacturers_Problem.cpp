// পারি না :P

#include<stdio.h>

int main()
{
    int tc,k,m,t;
    scanf("%d",&tc);
    while(tc--)
    {
        t=0;
        scanf("%d %d",&k,&m);
        int n=k;
        while(1)
        {

            t+=k;
            if(k>=m)
            break;
            k+=n;




        }
        printf("%d\n",t);
    }
    return 0;
}
