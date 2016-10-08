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
    int i,j,k,n;
    bool f[55];
    char a,b;
    string t,c;



    while(scanf("%d",&n)==1 && n)
    {
        memset(f,false,sizeof(f));
        vector<string>res(52);
        k=-1;
        for(i=0;i<n;i++)
        {
            cin>>a>>b>>c;
            t=a;
            t+=b;

            j=c.size();
            while(j)
            {
                k=(k+1)%n;
                if(!f[k])
                    j--;

            }
            //cout<<k<<" ";
            res[k]=t;
            f[k]=true;
        }

        for(i=0;i<n;i++)
        {
            if(i>0)
                cout<<" ";
            cout<<res[i];
        }
        cout<<endl;

    }
    return 0;
}
