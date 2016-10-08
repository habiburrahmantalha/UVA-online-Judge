#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

string city1,city2;

int LCS()
{
    int T[110][110],i,j;
    memset(T,0,sizeof(T));

    for(i=0;i<city1.size();i++)
    {
        for(j=0;j<city2.size();j++)
        {
            if(city1[i]==city2[j])
                T[i+1][j+1]=T[i][j]+1;
            else
                T[i+1][j+1]=max(T[i][j+1],T[i+1][j]);
        }
    }
    return T[city1.size()][city2.size()];
}



int main()
{
    int cities,t=1;
    while(getline(cin,city1))
    {
        if(city1=="#")
        break;
        getline(cin,city2);
        cities=LCS();
        printf("Case #%d: you can visit at most %d cities.\n",t++,cities);
    }
    return 0;
}
