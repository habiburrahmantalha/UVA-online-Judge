#include<stdio.h>

int main()
{
    //freopen("in.txt","r",stdin);
    double x[200],s;
    x['W']=1;
    x['H']=.5;
    x['Q']=.25;
    x['E']=.125;
    x['S']=.0625;
    x['T']=.03125;
    x['X']=.015625;
    int i,c;
    bool f;
    char y[210];
    while(scanf("%s",y))
    {
        if(y[0]=='*')
            break;
        c=0;
        f=false;
        s=0;
        for(i=1;y[i]!=0;i++)
        {

            if(y[i]=='/')
            {
                //printf("%.2lf ",s);
                if(s==1)
                    c++;
                s=0;
                continue;
            }
            //printf("%.2lf ",x[y[i]]);
            s+=x[y[i]];

        }
        printf("%d\n",c);
    }
    return 0;
}
