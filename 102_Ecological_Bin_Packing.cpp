#include<stdio.h>

int main()
{
    unsigned long long res[6],min,i,in,b1,g1,c1,b2,g2,c2,b3,g3,c3;
    char c[6][5]={"BCG","BGC","CBG","CGB","GBC","GCB"};
    while(scanf("%llu %llu %llu %llu %llu %llu %llu %llu %llu",&b1,&g1,&c1,&b2,&g2,&c2,&b3,&g3,&c3)==9)
    {

        res[0]=c1+b2+g1+b3+g2+c3;
        res[1]=c1+b3+g1+b2+g3+c2;
        res[2]=b1+c2+g1+c3+g2+b3;
        res[3]=b1+c3+g1+c2+g3+b2;
        res[4]=b1+g2+c1+g3+b3+c2;
        res[5]=b1+g3+c1+g2+b2+c3;

        min=res[0];
        in=0;
        for(i=1;i<6;i++)
        {
            //printf("%s %d\n",c[i],res[i]);
            if(min>res[i])
            {
                min=res[i];
                in=i;
            }
        }
        printf("%s %llu\n",c[in],min);
    }
    return 0;
}
