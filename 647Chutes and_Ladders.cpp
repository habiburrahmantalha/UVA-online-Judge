#include<stdio.h>
#include<string.h>

int main()
{
    int i,j,k,a,b,player,n;
    bool flag;
    int x[1001],L[100],C[100],BP[100],BN[100],G[7];
    for(i=0;;i++)
        {
            scanf("%d",&x[i]);
            if(x[i]==0)
            break;
        }
    while(1)
    {
        //memset(x,0,sizeof(x));
        memset(L,0,sizeof(L));
        memset(C,0,sizeof(C));
        memset(BP,0,sizeof(BP));
        memset(BN,0,sizeof(BN));
        memset(G,0,sizeof(G));
        flag=false;


        scanf("%d",&n);
        if(n==0)
        break;
        while(scanf("%d %d",&a,&b) && a && b)
        {
            if(a<b)
            L[a]=b;
            else
            C[b]=a;
        }
        while(scanf("%d",&a))
        {
            if(a==0)
            break;
            if(a<0)
            BN[-a]=1;
            else
            BP[a]=1;
        }
        for(j=0;j<i;j+=n)
        {

            for(k=0;k<n;k++)
            {

                if(G[k]+x[j+k]<100)
                G[k]+=x[j+k];
                else if(G[k]+x[j+k]==100)
                {
                    flag=true;
                    break;
                }
                else
                continue;

                if(L[G[k]])
                G[k]=L[G[k]];
                else if(C[G[k]])
                G[k]=C[G[k]];
                else if(BN[G[k]])
                G[k]-=x[j+k];
                else if(BP[G[k]])
                {
                    j++;
                    if(G[k]+x[j+k]<100)
                    G[k]+=x[j+k];
                    else if(G[k]+x[j+k]==100)
                    {
                        flag=true;
                        break;
                    }
                    else
                    continue;
                }

            }
            if(flag==true)
            break;
        }
        printf("%d\n",k+1);


    }
    return 0;
}
