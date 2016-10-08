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

char str1[310],str2[310];
int len1,len2;
int T[310][310];
vector<string>vs;
int LCS()
{
    memset(T,0,sizeof(T));
    int i,j,mx=0;
    for(i=0;i<len1;i++)
    {
        for(j=0;j<len2;j++)
        {
            if(str1[i]==str2[j])
            {
                if(i==0 || j==0)
                mx=max(mx,T[i][j]=1);
                else
                mx=max(mx,T[i][j]=T[i-1][j-1]+1);
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
    return mx;

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
        vs.push_back(s);
    }
    else
    {
        s+=str1[i];
        //cout<<s<<endl;
        find_LCS(i-1,j-1,s);
    }
}
int main()
{
    int tc,i,j,x;
    bool f=false;
    while(gets(str1))
    {
        if(f)
        printf("\n");
        gets(str2);
        len1=strlen(str1);
        len2=strlen(str2);
        x=LCS();
        if(x)
        {
            for(i=0;i<len1;i++)
            for(j=0;j<len2;j++)
                if(T[i][j]==x)
                    find_LCS(i,j,"");
            //cout<<x;
            sort(vs.begin(),vs.end());
            for(i=0;i<vs.size();i++)
                printf("%s\n",vs[i].c_str());
        }
        else
        printf("No common sequence.\n");
        f=true;
        vs.clear();
        if(gets(str1))
            continue;
        else
            break;


    }
    return 0;
}
