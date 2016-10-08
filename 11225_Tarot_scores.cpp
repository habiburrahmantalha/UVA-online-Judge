#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)


int main()
{
    double Oudlers[]={56.0,51.0,41.0,36.0};
    int t=1,i,tc,n,oudlers;
    double res,sum;
    string str1,str2,str3;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        sum=0;
        oudlers=0;
        for(i=0;i<n;i++)
        {
            cin>>str1;
            if(str1!="fool")
                cin>>str2>>str3;

            if(str1=="king")
            sum+=4.5;
            else if(str1=="queen")
            sum+=3.5;
            else if(str1=="knight")
            sum+=2.5;
            else if(str1=="jack")
            sum+=1.5;
            else
            sum+=0.5;

            if(str1=="fool" || str1=="one" || str1=="twenty-one" )
            {
                sum+=4;
                oudlers++;
            }
        }
        res = sum - Oudlers[oudlers];
        printf("Hand #%d\n",t++);
        if(res<0)
        printf("Game lost by %.0lf point(s).\n",-res);
        else
        printf("Game won by %.0lf point(s).\n",res);
        if(tc)
        printf("\n");

    }
    return 0;
}
