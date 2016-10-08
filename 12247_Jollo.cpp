#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int a[5],b[5],c[5];
bool win()
{
    //printf("%d %d %d\n",c[0],c[1],c[2]);
    int i,cn=0;
    for(i=0;i<3;i++)
    if(c[i]<0)
    cn++;

    if(cn>=2)
    return false;
    return true;
}

int main()
{
    int f[100];
    bool w;
    int i,j,k;
    while(scanf("%d %d %d %d %d",&a[0],&a[1],&a[2],&b[0],&b[1])==5 && a[0]+a[1]+a[1]+b[0]+b[1])
    {
        memset(f,0,sizeof(f));
        f[a[0]]=f[a[1]]=f[a[2]]=f[b[0]]=f[b[1]]=1;

        sort(a,a+3);

        w=false;
        for(k=1;k<=52;k++)
        {
            if(f[k]==0)
            {
                b[2]=k;
                c[0]=b[0];
                c[1]=b[1];
                c[2]=b[2];
                sort(c,c+3);
                //for(int l=0;l<3;l++)
                //printf("%d %d\n",a[l],c[l]);
                for(i=2;i>=0;i--)
                {
                    for(j=2;j>=0;j--)
                    {
                        if(a[i]>c[j] && c[j]!=-1)
                        {

                            c[j]=-1;
                            break;
                        }
                    }
                }
                if(win())
                {
                    w=true;
                    printf("%d\n",k);
                    break;
                }
            }

        }
        if(!w)
        printf("-1\n");
    }
    return 0;
}
