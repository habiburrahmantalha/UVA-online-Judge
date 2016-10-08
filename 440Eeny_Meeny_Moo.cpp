#include<stdio.h>
#include<string.h>

int n;

bool check(int m)
{
    bool city[n+1];
    memset(city,false,sizeof(city));
    int x=1,in=1,j;
    city[1]=true;
    while(1)
    {

        //printf("%d\n",in);
        if(city[2])
        {
            if(x==n)
            return true;
            else
            return false;
        }
        j=0;
        for(;;)
        {
            in+=1;
            if(in>n)
            in%=n;
            if(!city[in])
            {
                j++;
            }
            if(j==m)
            break;
            //printf("%d,j\n",j);
        }

        city[in]=true;
        x++;
    }
}
int main()
{
    int i;
    while(scanf("%d",&n) && n)
    {

        for(i=1;i ;i++)
        {

            if(check(i)==true)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
