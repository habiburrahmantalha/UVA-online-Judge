#include<stdio.h>
#include<string.h>

int main()
{
    freopen("in.txt","r",stdin);
    int y,x,i,s,e,c,mx,in,f[1000010],p,xs,xe;
    while(scanf("%d",&y)==1)
    {
        memset(f,0,sizeof(f));
        scanf("%d",&p);
        for(i=0;i<p;i++)
        {
            scanf("%d",&x);
            f[x]++;
        }
        c=0;
        for(i=1;i<=y;i++)
            c+=f[i];

        mx=c;
        s=1;
        e=y;
        in=1;
        for(;i<=p;i++,in++)
        {
            //printf("%d ,",c);

            if(f[in])
            {
                c-=f[in];
                xs=in+1;
            }
            if(f[i])
            {
                c+=f[i];
                xe=i;
            }
            if(mx<c)
            {
                mx=c;
                s=xs;
                e=xe;
            }
        }
        printf("%d %d %d\n",c,s,e);
    }
    return 0;
}
