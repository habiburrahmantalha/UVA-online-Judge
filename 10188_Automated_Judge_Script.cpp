#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

int m,n;
string solution[110],output[110];
bool is_ACC()
{
    if(n!=m)
    return false;

    for(int i=0;i<n;i++)
    if(solution[i]!=output[i])
    return false;

    return true;
}

bool is_PE()
{


    int i,j;
    string a,b;
    for(i=0;i<n;i++)
    for(j=0;j<solution[i].size();j++)
    if(isdigit(solution[i][j]))
    a+=solution[i][j];

    for(i=0;i<m;i++)
    for(j=0;j<output[i].size();j++)
    if(isdigit(output[i][j]))
    b+=output[i][j];

    //cout<<a<<b<<"*"<<endl;

    if(a!=b)
    return false;

    return true;


}

int main()
{
    int i,t=1;
    string a,b;
    char c[1000];
    while(gets(c)!=NULL)
    {
        n=atoi(c);
        if(n==0)
        break;
        a="";
        for(i=0;i<n;i++)
        {
            getline(cin,solution[i]);
            a+=solution[i];
        }

        gets(c);
        m=atoi(c);
        b="";
        for(i=0;i<m;i++)
        {
            getline(cin,output[i]);
            b+=output[i];
        }

        if(is_ACC())
            printf("Run #%d: Accepted\n",t++);
        else if(is_PE())
            printf("Run #%d: Presentation Error\n",t++);
        else
            printf("Run #%d: Wrong Answer\n",t++);
    }
    return 0;
}
