#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

int U[]={1,3,5,7,9,11,13,15,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57};
int L[]={2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58};
vector<int> y;

void encode(string x)
{

    for(int i=0;i<x.size();i++)
        if(isupper(x[i]))
        y.push_back(U[x[i]-'A']);
        else
            y.push_back(L[x[i]-'a']);
    //for(int i=0;i<y.size();i++)
    //cout<<y[i];
}
string decode()
{

    string x="";
    for(int i=0;i<y.size();i++)
        if(y[i]%2==0)
        x+='a'+(y[i]/2-1);
        else
            x+='A'+(y[i]-1)/2;
            //cout<<res;
    return x;
}
int main()
{
    int tc;
    string x;

    scanf("%d",&tc);
    while(tc--)
    {
        cin>>x;
        encode(x);
        sort(y.begin(),y.end());
        //cout<<x;
        do
        {
            x=decode();
            printf("%s\n",x.c_str());
        }while(next_permutation(y.begin(),y.end()));
        y.clear();
    }
    return 0;
}
