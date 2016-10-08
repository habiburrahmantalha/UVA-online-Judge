#include<map>
#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int res[110],in,l1,l2,s1[110],s2[110],t[110][110];

void LCS()
{
    int i,j;
    memset(t,0,sizeof(t));

    for(i=0;i<l1;i++)
    {
        for(j=0;j<l2;j++)
        {
            if(s1[i]==s2[j])
            {

                t[i+1][j+1]=t[i][j]+1;
            }
            else
            {
                t[i+1][j+1]=max(t[i][j+1],t[i+1][j]);
            }
        }
    }
    /*
    printf("        ");
    for(i=0;i<=l1;i++)
        printf("%3d ",s2[i]);
    printf("\n");
    for(i=0;i<=l1;i++)
    {
        if(i==0)
            printf("    ");
        if(i!=0)
        printf("%3d ",s1[i-1]);
        for(j=0;j<=l2;j++)
            printf("%3d ",t[i][j]);
        printf("\n");
    }
    printf("%d\n",t[l1][l2]);
    */
}
void backtrackLCS(int i,int j)
{

    if(i==0|| j==0)
        return;
    else if(s1[i-1]==s2[j-1])
    {
        res[in++]=s2[j-1];
        backtrackLCS(i-1,j-1);
    }
    else
    {
        if(t[i][j-1]>t[i-1][j])
            backtrackLCS(i,j-1);
        else
            backtrackLCS(i-1,j);
    }
}


int main()
{
    string s;
    map<string,int>mp;
    map<int,string>mpr;
    int n,i;
    while(cin>>s)
    {
        n=1;
        l1=0;
        s1[l1++]=n;
        mpr[n]=s;
        mp[s]=n++;
        while(cin>>s)
        {
            if(s=="#")
                break;
            if(!mp[s])
            {
                s1[l1++]=n;
                mpr[n]=s;
                mp[s]=n++;
            }
            else
                s1[l1++]=mp[s];

        }
        l2=0;;
        while(cin>>s)
        {
            if(s=="#")
                break;
            if(!mp[s])
            {
                s2[l2++]=n;
                mpr[n]=s;
                mp[s]=n++;
            }
            else
                s2[l2++]=mp[s];
        }
        in=0;
        LCS();

        backtrackLCS(l1,l2);
        for(i=in-1;i>0;i--)
            cout<<mpr[res[i]]<<" ";
            cout<<mpr[res[i]]<<endl;
        mp.clear();
        mpr.clear();
    }
    return 0;
}
