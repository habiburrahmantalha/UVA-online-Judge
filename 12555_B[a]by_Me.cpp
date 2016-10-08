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
    int tc,t=1,i,j;
    int a,b;
    char c[100];
    string str;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>str;
        i=0;
        while(isdigit(str[i]))
        {
            c[i]=str[i];
            i++;
        }
        c[i]=0;
        a=atoi(c);
        while(!isdigit(str[i]) && i < str.size())
        {
            i++;
        }
        j=0;
        while(isdigit(str[i]))
        {
            c[j++]=str[i];
            i++;
        }
        c[j]=0;
        b=atoi(c);
        //cout<<a<<b;
        printf("Case %d: %g\n",t++,(double)a*0.5+(double)b*0.05);

    }
    return 0;
}
