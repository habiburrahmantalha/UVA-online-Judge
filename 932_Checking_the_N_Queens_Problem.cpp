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

char g[35][35];
int n,Q;
vector<int>queen[35];

bool place(int i)
{
	int j;
	for(j=0;j<n;j++)
	{
		if( x[j]==i || abs(x[j]-i)==abs(j-k) )
			return false;
	}
	return true;
}

void position()
{
    Q=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        if(g[i][j]=='X')
        {
            Q++;

            q_r[i].push_back(j);
            q_c[j].push_back(i);

            R[i]=j;
            C[j]=i;
        }
    }
    if(Q>n)
        return;
    for(i=0;i<n;i++)
        if(queen[i].size()==0 || queen[i].size()>1)
            missplaced=true;
}
bool N_queen()
{

}
int main()
{
    while(scanf("%d",&n)=1)
    {
        for(i=0;i<n;i++)
        scanf("%s",&g[i]);

        position();

        if(Q>n)
            printf("NO\n");
        else
        {

        }
    }
    return 0;
}
