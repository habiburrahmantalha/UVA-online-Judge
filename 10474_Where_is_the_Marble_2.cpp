#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;


int main()
{
    int n,q,i,z,x[10010],y[10010],t=1;
    while(scanf("%d %d",&n,&q))
    {
        if(n==0 && q==0)
        break;
        for(i=0;i<n;i++)
        scanf("%d",&x[i]);

        sort(x,x+n);
        memset(y,0,sizeof(y));
        for(i=0;i<n;i++)
        {
            if(!y[x[i]])
            y[x[i]]=i+1;
        }
        printf("CASE# %d:\n",t++);
        for(i=0;i<q;i++)
        {
            scanf("%d",&z);
            if(!y[z])
            printf("%d not found\n",z);
            else
            printf("%d found at %d\n",z,y[z]);
        }
    }
    return 0;
}
