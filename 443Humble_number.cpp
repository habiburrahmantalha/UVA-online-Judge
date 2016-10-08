#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

set<long long> H;

void humblen()
{
    H.insert(1);
    set<long long> :: iterator it=H.begin();
    int i=0;
    while(H.size()<7000)
    {
        H.insert(*it*2);
        H.insert(*it*3);
        H.insert(*it*5);
        H.insert(*it*7);
        *it++;
    }
}
int main()
{
    int x;
    humblen();
    vector <long long> humble (H.begin (), H.end ());
    while(scanf("%d",&x))
    {
        if(x==0)
        break;
        if(x%100>10 && x%100<20)
        printf("The %dth humble number is %lld.\n",x,humble[x-1]);
        else if(x%1000>10 && x%1000<20)
        printf("The %dth humble number is %lld.\n",x,humble[x-1]);
        else if(x%10==1)
        printf("The %dst humble number is %lld.\n",x,humble[x-1]);
        else if(x%10==2)
        printf("The %dnd humble number is %lld.\n",x,humble[x-1]);
        else if(x%10==3)
        printf("The %drd humble number is %lld.\n",x,humble[x-1]);
        else
        printf("The %dth humble number is %lld.\n",x,humble[x-1]);

    }
    return 0;
}
