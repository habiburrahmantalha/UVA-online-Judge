//Problem Type : LCSubstring
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

int T[310][310];
vector<string>DNA,vs;
map<string,int>DNA_mp;
map<string,int> ::iterator it;
string str1,str2;
int len1,len2,n;

void LCS()
{
    memset(T,0,sizeof(T));
    int i,j;
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++ )
        {
            if(str1[i]==str2[j])
            {
                if(i==0 || j==0)
                T[i][j]=1;
                else
                T[i][j]=T[i-1][j-1]+1;
            }
            else
                T[i][j]=0;
        }
    }
    /*
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        printf("%d ",T[i][j]);
        printf("\n");
    }
    //*/

}
bool FIND(string s)
{
    for(int i=0;i<vs.size();i++)
    if(vs[i]==s)
    return true;
    return false;
}
void find_LCS(int i,int j,string s)
{

    if(i<0 || j<0 || T[i][j]==0)
    {
        reverse(s.begin(),s.end());
        if(!FIND(s))
        {
            vs.push_back(s);
            DNA_mp[s]++;
        }
    }
    else
    {
        s+=str1[i];
        //cout<<s<<endl;
        T[i][j]=0;
        find_LCS(i-1,j-1,s);
    }
}
int main()
{
    int tc,i,j;

    char str[100];
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            DNA.push_back(str);
        }
        for(i=0;i<n-1;i++)
        {
            for(j=i+1;j<n;j++)
            {
                str1=DNA[i];
                str2=DNA[j];
                len1=str1.size();
                len2=str2.size();
                LCS();
                for(i=len1-1;i>=0;i--)
                for(j=len2-1;j>=0;j--)
                    if(T[i][j])
                        find_LCS(i,j,"");


                for(i=0;i<vs.size();i++)
                    printf("%s\n",vs[i].c_str());
                vs.clear();
            }
        }

        DNA_mp.clear();

    }
    return 0;
}
