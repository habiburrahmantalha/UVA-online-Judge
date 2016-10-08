//Problem Type :
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
    int x,i,j,tc,n;
    string a,b;
    vector<string>ins;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        x=0;
        for(i=0;i<n;i++)
        {
            cin>>a;
            if(a=="LEFT")
            {
                x--;
                ins.push_back(a);
            }
            else if(a=="RIGHT")
            {
                x++;
                ins.push_back(a);
            }
            else
            {
                cin>>b>>j;
                a=ins[j-1];
                if(a=="LEFT")
                {
                    x--;
                    ins.push_back(a);
                }
                else if(a=="RIGHT")
                {
                    x++;
                    ins.push_back(a);
                }
            }

        }
        printf("%d\n",x);
        ins.clear();
    }
    return 0;
}
