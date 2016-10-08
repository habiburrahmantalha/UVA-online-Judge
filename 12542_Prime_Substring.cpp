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

bool prime[100010];
void sieve()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    for(int i=2;i*i<100000;i++)
    {
        if(prime[i])
        for(int j=i+i;j<100010;j+=i)
        prime[j]=false;
    }
}
int to_int(string x)
{
    //cout<<x<<" *";
    int i,num=0,y=1;
    for(i=x.length()-1;i>=0;i--)
    {
        num+=(x[i]-'0')*y;
        y*=10;
    }
    return num;
}

int main()
{
    string str;
    sieve();
    int i,j,n;
    vector<int>m;
    while(cin>>str && str!="0")
    {
        m.clear();
        for(i=0;i<str.length();i++)
        {
            for(j=0;i+j<str.length() && j<=6 ;j++)
            {
                if(j==0)
                {
                    n=to_int(str.substr(i,j+1));
                    //cout<<str[i+j]<<" "<<str.substr(i,j+1)<<endl;
                    //cout<<n<<endl;
                    if(n<=100000 && prime[n])
                    m.push_back(n);
                }
                else if(str[i+j]=='1' || str[i+j]=='3' || str[i+j]==7 || str[i+j]=='9')
                {
                    n=to_int(str.substr(i,j+1));
                    //cout<<str[i+j]<<" "<<str.substr(i,j+1)<<endl;
                    //cout<<n<<endl;
                    if(n<=100000 && prime[n])
                    m.push_back(n);

                }

            }
        }
        sort(m.begin(),m.end());
        printf("%d\n",m[m.size()-1]);
    }
    return 0;
}
