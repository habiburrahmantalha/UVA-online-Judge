#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int N,M,i,x,l,u;
    vector<int> L;
    vector<int>::iterator low,up;
    while(scanf("%d",&N)==1)
    {

        L.clear();
        for(i=0;i<N;i++)
        {
            scanf("%d",&x);
            L.push_back(x);
        }


        scanf("%d",&M);
        for(i=0;i<M;i++)
        {
            scanf("%d",&x);

            low=lower_bound (L.begin(), L.end(),x);
            up= upper_bound (L.begin(), L.end(),x);

            l=int(low- L.begin());
            u=int(up - L.begin());
            if(l==0)
                printf("X");
            else
                printf("%d",L[l-1]);
            if(u==N)
                printf(" X\n");
            else
                printf(" %d\n",L[u]);

        }
    }
    return 0;

}
