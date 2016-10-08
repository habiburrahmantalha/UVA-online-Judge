#include<stdio.h>
#include<string.h>
#include<string>
#include<stack>
#include<algorithm>
#include<iostream>
using namespace std;

int n;
string str;
stack<string> st;

void nuth_permutation(string u,int i)
{
    if(u.size()==n)
    {
        st.push(u);
        return;
    }
    for(int j=u.size();j>=0;j--)
    {
        //cout<<u<<endl;
        string v=u;
        v.insert(v.begin()+j,str[i]);
        //cout<<v<<endl;
        nuth_permutation(v,i+1);

    }
}

int main()
{
    string s;
    bool f=false;

    while(cin>>str)
    {
        if(f)
        printf("\n");
        f=true;
        n=str.size();
        s="";
        s+=str[0];
        nuth_permutation(s,1);
        while(!st.empty())
        {
            cout<<st.top()<<endl;;
            st.pop();
        }

    }
    return 0;
}
