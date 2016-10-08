#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n,x,i;
    vector<int> age;
    while(scanf("%d",&n) && n)
    {
        if(n==0)
        break;
        age.clear();

        while(n--)
        {
            scanf("%d",&x);
            age.push_back(x);
        }
        sort(age.begin(),age.end());
        for(i=0;i<age.size();i++)
        {
            printf("%d",age[i]);
            if(i==age.size()-1)
            printf("\n");
            else
            printf(" ");
        }
    }
    return 0;
}
