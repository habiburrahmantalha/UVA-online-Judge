#include<stdio.h>
#include<string.h>

int main()
{
    int n,m,c,i,a[30],b[100000],tc=1,cap,max;
    bool t[30],f;
    while(scanf("%d %d %d",&n,&m,&c) && n && m && c)
    {
        max=0;
        cap=0;
        f=false;
        memset(t,false,sizeof(t));

        for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

        for(i=1;i<=m;i++)
        scanf("%d",&b[i]);

        printf("Sequence %d\n",tc++);
        for(i=1;i<=m;i++)
        {

            if(t[b[i]]==true)
            {
                cap-=a[b[i]];
                t[b[i]]=false;
                if(cap<0)
                cap=0;
            }
            else
            {
                cap+=a[b[i]];
                if(max<cap)
                max=cap;
                t[b[i]]=true;
                if(cap>c)
                {
                    printf("Fuse was blown.\n\n");
                    f=true;
                    break;
                }
            }
        }
        if(f==false)
        {
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n",max);
        }
    }
    return 0;
}
