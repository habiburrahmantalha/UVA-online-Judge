#include<stdio.h>
#include <stdlib.h>


int m=10000;
int huge_mod(int M,int p)
{
    //printf("%d %d\n",M,p);
        int in, d,x,i,y[100];
        in=0;
        d=1;

        x=p;
        while(x)
        {
            y[in++]=x%2;
            x/=2;
        }
        for(i=in-1;i>=0;i--)
        {
            d=(d*d)%m;
            //if(d==0)
            //d=1;
            printf("%d*\n",d);
            if(y[i]==1)
                {
                    d=(d*M)%m;
                    //if(d==0)
                    //d=1;
                }
        }
        //printf("%d\n",d);
        return d;
}

int main()
{
    int i,M,a[11],in,x,y,tc=1;


    char ch;
    while(scanf("%d",&M)==1)
    {
        in=0;
        while(1)
        {
            scanf("%d%c",&a[in++],&ch);
            if(ch=='\n')
            break;
        }
        x=a[in-1];
            for(i=in-2;i>=0;i--)
            {


                y=a[i];
                //printf("%d %d\n",M,x);
                x=huge_mod(y,x);
            }
            printf("Case %d: %d",tc++,x);



    }

    return 0;
}
