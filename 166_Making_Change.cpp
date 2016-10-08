#include<stdio.h>
#include<string.h>

int t[100000],b[100000],v[]={5,10,20,50,100,200},limit,c[10];


void change()
{
    //memset(b,0x7F,sizeof(b));
    int i,j;
    for(i=0;i<=100000;i++)
    b[i]=100000000;
    b[0]=0;
    for(i=0;i<6;i++)
    {
        for(j=0;j<=100000-v[i];j+=5)
        {
            if(b[j]!=100000000)
            if(b[j+v[i]]>b[j]+1)
                b[j+v[i]]=b[j]+1;

        }

    }
}
void pay()
{
    //memset(t,0,sizeof(t));
    int i,k,j;
    for(i=0;i<=limit;i++)
    t[i]=100000000;
    t[0]=0;
    for(i=0;i<6;i++)
    {
        if(c[i])
        for(j=0;j<c[i];j++)
        {
            for(k=limit-v[i];k>=0;k-=5)
            {
                    if(t[k]!=100000000)
                    if(t[k+v[i]]>t[k]+1)
                        t[k+v[i]]=t[k]+1;
            }
        }
    }
    //for(i=0;i<limit;i++)
    //if(t[i]!=100000000)
    //printf("%d ",t[i]);
}
int main()
{
    //freopen("in.txt","r",stdin);
    change();
    int y,i,j,k,min;
    double x;
    while(scanf("%d %d %d %d %d %d",&c[0],&c[1],&c[2],&c[3],&c[4],&c[5]))
    {
        if(!c[0] &&!c[1] &&!c[2] &&!c[3] &&!c[4] &&!c[5])
            break;
        limit=c[0]*5+c[1]*10+c[2]*20+c[3]*50+c[4]*100+c[5]*200;

        scanf("%lf",&x);
        x*=100;
        x+=.000000001;
        y=int(x);
        //printf("%d %d ",y,limit);
        pay();
        min=100000000;
        ///*
        for(i=y;i<=limit;i+=5)
        {
            //if(t[i]!=100000000)
            //printf("%d ",t[i]);
            if(t[i]+b[i-y]<min)
            {


                min=t[i]+b[i-y];
            }
        }
        //*/
        printf("%3d\n",min);
    }
    return 0;
}
