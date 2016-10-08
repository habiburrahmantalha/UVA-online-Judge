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

struct sorter
{
    int a,b;
    sorter();
    sorter(int a,int b):a(a),b(b){};

};
bool cmp(sorter a,sorter b)
{

    if(a.a==b.a)
        return a.b>b.b;
    return a.a < b.a;

}
vector<sorter>L;
int main()
{
    int tc;
    int n,m,i,a,b,j,mx,cnt;
    bool ln=false;
    scanf("%d",&tc);

    while(tc--)
    {
        if(ln)
            printf("\n");
        ln=true;
        scanf("%d %d",&m,&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            L.push_back(sorter(a,b));
        }
        sort(L.begin(),L.end(),cmp);
        //for(i=0;i<n;i++)
            //cout<<L[i].a<<" "<<L[i].b<<endl;
        a=L[0].a;
        b=L[0].b;
        cnt=1;
        for(i=1;i<n;i++)
        {
            mx=0;
            while(L[i].a<=b && i<n)
            {
                if(L[i].b>mx)
                {
                    mx=L[i].b;
                    j=i;

                }
                i++;
            }
            //cout<<mx<<endl;
            b=mx;
            i=j;
            cnt++;


        }
        printf("%d\n",cnt);
        L.clear();
    }
    return 0;
}
