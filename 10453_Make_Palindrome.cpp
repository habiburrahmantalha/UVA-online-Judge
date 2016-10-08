//Problem Type : palindrom
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
int mn;
string str,res;
int v[1010][1010];
void make_palindrom(int i,int j,string a,int k )
{
    if(v[i][k]<k)
    return;

    if(i>=j)
    {
        if(mn>k)
        {
            if(i==j)
            {
                res=a;
                res+=str[i];
                reverse(a.begin(),a.end());
                res+=a;

            }
            else
            {
                res=a;
                reverse(a.begin(),a.end());
                res+=a;
            }
            mn=k;
        }
        return;

    }
    if(str[i]==str[j])
    {
        v[i+1][j+1]=k;
        make_palindrom(i+1,j-1,a+str[i],k);

    }
    else
    {
        v[i+1][j]=k+1;
        make_palindrom(i+1,j,a+str[i],k+1);
        v[i][j+1]=k+1;
        make_palindrom(i,j-1,a+str[j],k+1);
    }
}

int main()
{
    while(cin>>str)
    {
        mn=0x7F;
        memset(v,0x7F,sizeof(v));
        make_palindrom(0,str.size()-1,"",0);
        cout<<mn<<" "<<res<<endl;
    }
    return 0;
}
