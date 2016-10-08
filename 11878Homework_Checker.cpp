#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    //freopen("in.txt","r",stdin);
    char x[10],y[10],z[10],ch;
    int a,b,c,in,count=0;
    bool f,p;
    while(1)
    {
        f=false;
        ch=getchar();
        if(ch==EOF)
        break;

        memset(x,0,sizeof(x));
        in=0;
        while(1)
        {
            if(ch==43 )
            {
                p=true;
                break;
            }
            if(ch==45)
            {
                p=false;
                break;
            }
            x[in++]=ch;
            ch=getchar();
        }
        a=atoi(x);
        //printf("%d\n",a);

        memset(y,0,sizeof(y));
        in=0;
        while(1)
        {
            ch=getchar();
            if(ch==61)
            break;
            y[in++]=ch;

        }
        b=atoi(y);
        //printf("%d\n",b);

        memset(z,0,sizeof(z));
        in=0;
        while(1)
        {
            ch=getchar();
            if(ch==10)
            break;
            if(ch==63)
            {
                f=true;
                break;
            }
            z[in++]=ch;

        }
        c=atoi(z);
        //printf("%d\n",c);

        if(f==false)
        {
            if(p==true )
            {

                if(a+b==c)
                count++;
            }
            else if(a-b==c)
            count++;
        }

    }
    printf("%d\n",count);
    return 0;
}
