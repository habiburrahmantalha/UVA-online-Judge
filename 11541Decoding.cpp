#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,k,tc,i,j,z,in,len,l;
    char ch,x[1000],y[4];
    scanf("%d",&tc);
    for(k=1;k<=tc;k++)
    {
        scanf("%s",x);
        len=strlen(x);
        j=in=0;
        printf("Case %d: ",k);
        for(i=1;i<len;i++)
        {

            if(isdigit(x[i]))
            {
                y[in++]=x[i];
            }
            else
            {
                y[in]=0;
                in=0;
                z=atoi(y);
                for(l=0;l<z;l++)
                printf("%c",x[j]);
                j=i;
            }
        }
        y[in]=0;
        z=atoi(y);
        for(l=0;l<z;l++)
        printf("%c",x[j]);
        printf("\n");
    }
    return 0;
}
