#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<stack>
using namespace std;

stack<pair<int,int> >st;
stack<int>s;

void sum()
{
    int c,a,b,r;
    c=0;
    while(!st.empty())
    {
        a=st.top().first;
        b=st.top().second;
        st.pop();
        r=a+b+c;
        if(r>9)
        c=1;
        else
        c=0;
        s.push(r%10);
    }
    if(c)
    s.push(1);
}

void print()
{
    while(!s.empty())
    {
        printf("%d",s.top());
        s.pop();
    }
    printf("\n");
}
int main()
{
    int tc,i,n,a,b;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            st.push(make_pair(a,b));
        }
        sum();
        print();
        if(tc!=0)
        printf("\n");
    }
    return 0;
}
