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
    int tc,t=1;
    char x[100];
    while(scanf("%s",x))
    {
        if(strcmp(x,"*")==0)
        break;

        if(strcmp(x,"Hajj")==0)
        printf("Case %d: Hajj-e-Akbar\n",t++);
        else if(strcmp(x,"Umrah")==0)
        printf("Case %d: Hajj-e-Asghar\n",t++);

    }
    return 0;
}
