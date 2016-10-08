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
    int tc,i,n,m,x,sz;

    multiset<long long>ms;
    multiset<long long>::iterator it;
    long long a[30010];


    scanf("%d",&tc);
    while(tc--)
    {
        ms.clear();
        scanf("%d %d",&n,&m);

        for(i=0;i<n;i++)
            cin>>a[i];

        sz=1;
        ms.insert(a[0]);
        it=ms.begin();
        bool f=false;
        for(i=0;i<m;i++)
        {
            scanf("%d",&x);
            while(x>sz)
            {
                ms.insert(a[sz]);
                if(*it>a[sz])
                it--;

                sz++;
            }
            if(!f)
                f=true;
            else
                it++;
            cout<<*it<<endl;

        }
        if(tc)
        cout<<endl;
    }
    return 0;
}
