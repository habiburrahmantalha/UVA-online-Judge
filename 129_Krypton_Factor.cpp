#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int L,N;
vector<string>S;
void Krypton_Factor()
{
    string u,v;
    char i,j,k;
    S.push_back("A");

    for(i='B';i<='Z';i++)
    {
        u=S[S.size()-1];
        u+=i;
        S.push_back(u);
        k=S.size()-1;
        for(j=0;j<k;j++)
        {
            v=u;
            v+=S[j];

            S.push_back(v);
            //cout<<u<<endl;;
        }

    }
    /*
    for(i=0;i<S.size();i++)
    {
        cout<<S[i]<<endl;
        if(S[i].size()==80)
        break;


    }
    */
}

int main()
{
    Krypton_Factor();
    while(scanf("%d %d",&N,&L) && L+N)
    {
        cout<<S[N]<<endl;
    }
    return 0;
}
