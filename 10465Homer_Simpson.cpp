#include<stdio.h>
#include<algorithm>
#include<string.h>

using namespace std;

int main()
{
    int m,n,t;
    int time[10010];
    bool f;
    while(scanf("%d %d %d",&m,&n,&t)==3)
    {
        f=false;
        memset(time,0,sizeof(time));

        if(m>n)
        swap(m,n);

        time[m]=1;
        time[n]=1;

        for(int i=m;i<=t;i++)
        {
            if(time[i])
            {
                if (i+m<=t)
                time[i+m]=time[i]+1;
                if (i+n<=t)
                time[i+n]=time[i]+1;
            }
        }
        //for(int i=m;i<=t;i++)
        {
            //printf("%d ",time[i]);
        }
        if(time[t])
            printf("%d\n",time[t]);
        else
        {
            for(int i=t-1;i>=0;i--)
            if(time[i])
            {
                printf("%d %d\n",time[i],t-i);
                f=true;
                break;

            }
            if(f==false)
            printf("0 %d\n",t);
        }

    }
    return 0;
}
