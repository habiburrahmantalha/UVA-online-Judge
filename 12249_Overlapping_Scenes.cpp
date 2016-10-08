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

int n;
vector<string> str;

int common(string a,string b)
{
    int i,j,k=0;

    for(i=a.size()-1,j=1;i>=0 && j<b.size();i--,j++)
    {
        if(a.substr(i)==b.substr(0,j))
        {
            k=j;
            if(i==0 || j==b.size()-1)
                k=0;

        }
    }
    //cout<<k<<" ";

    return k;

}

int main()
{
    int tc,t=1,mx,i,j,k;
    string s;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            cin>>s;
            str.push_back(s);
        }

        mx=0;
        sort(str.begin(),str.end());
        do
        {
            i=0;
            j=1;
            s=str[i];
            while(j<n)
            {
                k=common(str[i],str[j]);
                if(k)
                {
                    for(;k<str[j].size();k++)
                        s+=str[j][k];
                    i++;
                    j++;
                }
                else
                    j++;

            }
            if(s.size()>mx)
                mx=s.size();
            //cout<<s<<endl;


        }while(next_permutation(str.begin(),str.end()));

        printf("Case %d: %d\n",t++,mx);
        str.clear();
    }
    return 0;
}
