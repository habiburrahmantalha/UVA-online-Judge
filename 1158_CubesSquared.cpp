#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;
#define N 400000
int C[N+10];

void cubes()
{
    vector<int>v;
    int i,x,y=0,j;

    for(i=1; ;i++)
    {
        x=i*i*i;

        if(x>N)
            break;
        v.push_back(x);
    }
    for(i=1; ;i++)
    {
        y+=i*i;

        if(y>N)
            break;
        v.push_back(y);
    }
    memset(C,0,sizeof(C));
    C[0]=1;
    for(i=0;i<v.size();i++)
    {
        for(j=0;j<=N-v[i];j++)
        {
            if(C[j])
            {
                if(C[j+v[i]]==0)
                    C[j+v[i]]=C[j]+1;
                else
                {

                    if(C[j+v[i]]>C[j]+1)
                    C[j+v[i]]=C[j]+1;
                }
            }

        }
    }
}
int main()
{
    cubes();
    int x;
    while(scanf("%d",&x) && x>=0)
    {
        printf("%d\n",C[x]-1);
    }
    return 0;
}
