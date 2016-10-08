#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

char str[55];
int res[10000];

bool is_100(int in)
{
    /*
    for(int k=0;k<in;k++)
        printf("%d",res[k]);
        printf("\n");
//*/
    if(in<3)
    return false;
    if(in==3 && res[0]==1 && res[1]==0 && res[2]==0)
    return true;



    for(int i=0;i<in-1;i++)
    {
        //printf("%d ",i);
        res[i]=(res[i]+res[i+1])%10;
    }
    //printf("\n");

    return is_100(in-1);

}
void Yuanfen()
{
    int i,j,l,x,in;
    string s;
    l=strlen(str);
    for(i=1;i<10000;i++)
//i=634;
    {
        in=0;
        for(j=l-1;j>=0;j--)
        {
            x=str[j]-'A'+i;
            while(x)
            {
                res[in++]=x%10;
                x/=10;
            }
        }
        reverse(res,res+in);
        if(is_100(in))
        {
            printf("%d\n",i);
            return ;
        }
    }
    printf(":(\n");
}

int main()
{
    while(scanf("%s",str)==1)
    {
        Yuanfen();
    }

    return 0;
}
