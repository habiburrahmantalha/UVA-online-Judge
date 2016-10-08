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
    int tc,i,a,c,res,N,W,d[1010],w[1010];
    cin>>tc;
    while(tc--)
    {
        cin>>W>>N;
        for(i=0;i<N;i++)
            cin>>d[i]>>w[i];

        c=0;
        a=0;
        res=0;
        for(i=0;i<N;i++)
        {
            if(c+w[i]<W)
            {
                c+=w[i];
                a=d[i];

            }
            else if(c+w[i]==W)
            {
                c=0;
                a=d[i];
                res+=a*2;

            }
            else
            {
                a=d[i];
                res+=a*2;
                c=0;
                i--;
            }

        }
        if(c)
            res+=a*2;

        cout<<res<<endl;
    }
    return 0;
}
