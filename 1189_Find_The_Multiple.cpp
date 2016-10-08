#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

vector<string> v[20];
string res[210];

bool divn(string x,int n)
{
    //cout<<x<<" "<<n<<endl;
    int rem=0,len,i;
    len=x.size();

    for(i=0;i<len;i++)
        rem=(rem*10+(x[i]-'0'))%n;

    if(rem==0)
    return true;
    else
    return false;
}
string multiple(int n)
{
    int i,j;
    for(i=2;i<=19;i++)
    {
        for(j=0;j<v[i].size();j++)
        if(divn(v[i][j],n))
        return v[i][j];
    }
}
void precal()
{
    int i,j;
    string s;
    v[1].push_back("1");
    for(i=2;i<=19;i++)
    {
        for(j=0;j<v[i-1].size();j++)
        {
            s=v[i-1][j];
            v[i].push_back(s+"1");
            v[i].push_back(s+"0");
        }
        //printf("%d %d\n",i,v[i].size());
    }

    for(i=2;i<=200;i++)
    {
        res[i]=multiple(i);
        //cout<<res[i]<<endl;
    }
    res[1]="10";

}
int main()
{
    precal();
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        printf("%s\n",res[n].c_str());
    }
    return 0;
}
