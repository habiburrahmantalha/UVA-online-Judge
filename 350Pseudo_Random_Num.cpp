#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>
int check[1000000];
int pg(int zz,int ii,int mm,int ll)
{
    memset(check,0,sizeof(check));
        int count=0;
        int x=ll;
        check[x]=1;
        while(1)
        {
            x=((zz*x)+ii)%mm;

            count++;
            //printf("%d\n",x);
            if(check[x])
            {
                if(x!=ll)
                count--;
                //printf("%d\n",(x%4)+1);
                break;
            }
            check[x]=1;

        }
        return count;
}

int main()
{
    //freopen("in.txt","r",stdin);
    memset(check,0,sizeof(check));
    int z,i,l,m,a,x,t=1,count;
    while(1)
    {
        scanf("%d %d %d %d",&z,&i,&m,&l);

        if(z==0 && i==0 && m==0 && l==0)
        break;
        count=pg(z,i,m,l);
        printf("Case %d: %d\n",t++,count);
    }
    return 0;
}
