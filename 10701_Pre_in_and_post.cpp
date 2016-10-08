//tree
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;

map<int,char> T;
int i;
void construct(string pre,string in,int ind)
{
    string s1,s2;
    int j;
    T[ind]=pre[i];
    if(in.size()==1)
    return ;
    s1="";
    for(j=0;j<in.size();j++)
    if(in[j]==pre[i])
    break;
    else
    s1+=in[j];
    if(s1.size()>0)
    {
        i++;
        construct(pre,s1,ind*2+1);
    }
    s2="";
    for(j=j+1;j<in.size();j++)
    s2+=in[j];
    if(s2.size()>0)
    {
        i++;
        construct(pre,s2,ind*2+2);
    }
}
void post_order(int j)
{
    if(T[j]==0)
    return;

    post_order(j*2+1);
    post_order(j*2+2);
    printf("%c",T[j]);
}
int main()
{
    string pre,in;
    int tc,n;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>n>>pre>>in;
        i=0;
        construct(pre,in,0);
        post_order(0);
        printf("\n");
        T.clear();
    }
    return 0;
}
