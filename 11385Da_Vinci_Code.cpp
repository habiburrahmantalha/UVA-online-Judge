#include<stdio.h>
#include<string.h>
#include<ctype.h>

long long fib[91];

void fibonacci()
{
    fib[0]=1;
    fib[1]=1;
    for(int i=2;i<91;i++)
    fib[i]=fib[i-1]+fib[i-2];
    //for(int i=0;i<91;i++)
    //printf("%d %lld\n",i,fib[i]);
}

int findplace(int x)
{
    for(int i=1;i<91;i++)
    if(x==fib[i])
    return i;

}

int main()
{
    //freopen("in.txt","r",stdin);
    fibonacci();

    int tc,n,c[110],len,place,in,max;
    char ctext[110],dtext[110];

    scanf("%d",&tc);
    for(int i=0;i<tc;i++)
    {
        scanf("%d",&n);
        for(int j=0;j<n;j++)
            scanf("%d",&c[j]);

        getchar ();
        gets(ctext);
        len=strlen(ctext);

        in=0;
        max=0;
        memset(dtext,' ',sizeof(dtext));

        for(int j=0;j<len;j++)
        {
            if(isupper(ctext[j]))
            {
                place=findplace(c[in++]);
                if(max<place)
                max=place;
                dtext[place-1]=ctext[j];
            }

        }
        dtext[max]=0;
        printf("%s\n",dtext);
    }
    return 0;
}
