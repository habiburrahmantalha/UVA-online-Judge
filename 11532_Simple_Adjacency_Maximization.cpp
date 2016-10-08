//Problem Type : binary manipulation
//Time :
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

    int tc,i,j,P,Q;
    long long res;
    string str;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&P,&Q);

        str="";
        while(P>=2 && Q>=1)
        {
            str+="101";
            P-=2;
            Q--;
        }
        if(P==1 && Q>=1)
        {
            str="01"+str;
            P--;
            Q--;
        }

        while(P>=1 && Q==0)
        {
            str+="1";
            P--;
        }
        res=0;
        for(i=0;i<str.size();i++)
        {
            if(str[i]=='1')
            {
                res<<=1;
                res|=1;
            }
            else
            {
                res<<=1;
            }
        }

        printf("%lld\n",res);
    }
    return 0;
}
