#include<stdio.h>
#include<math.h>
long double u,v,t,s,a,x,y,z;

void s_a()
{
    a=(y-x)/z;
    s=(x*z)+(0.5*a*z*z);
    printf("%.3Lf %.3Lf\n",s,a);
}

void s_t()
{

    t=(y-x)/z;
    s=(x*t)+(0.5*z*t*t);
    printf("%.3Lf %.3Lf\n",s,t);
}
void v_t()
{
    v=sqrt(x*x+2*y*z);
    t=(v-x)/y;
    printf("%.3Lf %.3Lf\n",v,t);
}
void u_t()
{
    u=sqrt(x*x-2*y*z);
    t=(x-u)/y;
    printf("%.3Lf %.3Lf\n",u,t);
}
int main()
{
    int c,tc=1;
    while(scanf("%d",&c) &&c)
    {
        scanf("%Lf %Lf %Lf",&x,&y,&z);
        printf("Case %d: ",tc++);
        if(c==1)
        s_a();
        else if(c==2)
        s_t();
        else if(c==3)
        v_t();
        else if(c==4)
        u_t();

    }
    return 0;
}
