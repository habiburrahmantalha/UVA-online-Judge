#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

set<int> s;

bool valid()
{
    int i;
    set<int> :: iterator it;

    for(i=1,it=s.begin();it!=s.end();it++,i++)
    {
        if(i!=*it)
            return false;
    }
    return true;

}
void cal()
{
    int c=0,n=7,i,j,k,l,m,m1,m2;

    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
            for(l=1;l<=n;l++)
                for(m=1;m<=n;m++)
                    for(m1=1;m1<=n;m1++)
                    for(m2=1;m2<=n;m2++)
                {
                    s.clear();
                    s.insert(i);
                    s.insert(j);
                    s.insert(k);
                    s.insert(l);
                    s.insert(m);
                    s.insert(m1);
                    s.insert(m2);

                    if(valid())
                        c++;
                }

    printf("%d\n",c);
}
int main()
{
    cal();
    //scanf("%d",&tc);
}
