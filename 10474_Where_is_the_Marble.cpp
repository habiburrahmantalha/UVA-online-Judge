#include<stdio.h>
#include<vector>
#include<list>
using namespace std;

int main()
{
    list<int>lst;
    list<int>::iterator it;
    int n,q,i,x,t=1;
    bool f;
    while(scanf("%d %d",&n,&q))
    {
        if(n==0 && q==0)
        break;

        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            lst.push_back(x);
        }
        lst.sort();
        //lst.unique();
        printf("CASE# %d:\n",t++);
        for(i=0;i<q;i++)
        {
            scanf("%d",&x);
            int c=0;
            f=false;
            for(it=lst.begin();it!=lst.end();it++)
            {
                c++;
                if(*it==x)
                {
                    f=true;
                    break;
                }
            }
            if(f)
            printf("%d found at %d\n",x,c);
            else
            printf("%d not found\n",x);
        }
        lst.clear();
    }
    return 0;
}
