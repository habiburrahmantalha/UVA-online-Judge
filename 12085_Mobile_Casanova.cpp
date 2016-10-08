#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    long long n,i,y,x[100010],t=1,res[10000],z,j,k;
    bool f;
    while(scanf("%lld",&n) && n)
    {
        for(i=0;i<n;i++)
        scanf("%lld",&x[i]);

        printf("Case %lld:\n",t++);
        for(i=0;i<n;i++)
        {
            f=false;
            printf("0%lld",x[i]);
            z=x[i];
            while(1)
            {
                if(x[i+1]-1==x[i] && i+1<n)
                {
                    y=x[i+1];
                    f=true;
                    i++;
                }
                else
                {
                    if(f)
                    {
                        j=0;
                        while(y)
                        {
                            if(y%10!=z%10)
                            {

                                res[j++]=y%10;
                                y/=10;
                                z/=10;
                                k=j;

                            }
                            else
                            {
                                res[j++]=y%10;
                                y/=10;
                                z/=10;
                                //break;
                            }
                        }
                        printf("-");
                        j=k;
                        while(j--)
                            printf("%lld",res[j]);
                        printf("\n");
                        break;
                    }
                    else
                    {
                        printf("\n");
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}
