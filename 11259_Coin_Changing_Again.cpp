#include<stdio.h>
#include<string.h>

int main()
{
    int tc,c[5],d[10],v,i,j,k,way[100010],q;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf("%d %d %d %d %d",&c[0],&c[1],&c[2],&c[3],&q);

        while(q--)
        {
            scanf("%d %d %d %d %d",&d[0],&d[1],&d[2],&d[3],&v);

            for(i=0;i<4;i++)
            {
                if(d[i]>v/c[i])
                    d[i]=v/c[i];
            }
            memset(way,0,sizeof(way));

            way[0]=1;

            for(i=0;i<4;i++)
            {
                for(j=0;j<d[i];j++)
                {
                    for(k=v;k>=0;k--)
                    {
                        if(way[k] && k+c[i]<=v)
                        {
                            way[k+c[i]]++;
                        }
                    }
                }
            }
            for(i=0;i<=v;i++)
                printf("%d ",way[i]);
            printf("\n");
            printf("%d\n",way[v]);
        }
    }
    return 0;
}
