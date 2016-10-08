#include<stdio.h>
#include<string.h>
int main()
{
    //freopen("in.txt","r",stdin);
    int a[10000][2]={0,0},x=0,i,n;
    bool f;

    while(scanf("%d",&n)==1)
    {

        f=false;
        for(i=0;i<x;i++)
        {
            if(a[i][0]==n)
            {
                a[i][1]++;

                f=true;
                break;
            }
        }
        if(f==false)
        {
            a[x][0]=n;
            a[x][1]=1;
            x++;
        }
    }
    for(i=0;i<x;i++)
    printf("%d %d\n",a[i][0],a[i][1]);
    return 0;
}
