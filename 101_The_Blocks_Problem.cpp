//Problem Type :
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
#include<stack>
using namespace std;
#define PI 2 * acos (0.0)

stack<int>S[30];
int P[30];

void reset(int x)
{
    while(!S[x].empty())
    S[x].pop();

    S[x].push(x);
    P[x]=x;
}

void pile(int a,int b)
{
    if(S[P[a]].top()==a)
    {
        int c=S[P[a]].top();
        S[P[a]].pop();
        P[c]=P[b];
        S[P[b]].push(c);
        return;
    }
    else
    {
        int c=S[P[a]].top();
        S[P[a]].pop();
        pile(a,b);
        P[c]=P[b];
        S[P[b]].push(c);
    }
}
void print(int i)
{
    if(S[i].empty())
        return;
    else
    {
        int c=S[i].top();
        S[i].pop();
        print(i);
        printf(" %d",c);
    }
}
int main()
{
    int a,b,n,i,t=1;
    string op,des;

    while(scanf("%d",&n)==1)
    {
        for(i=0;i<n;i++)
        reset(i);
        while(cin>>op && op!="quit")
        {
            cin>>a>>des>>b;
            //cout<<t++<<endl;
            if(a==b || P[a]==P[b])
            continue;
            if(op=="move")
            {

                if(des=="onto")
                {
                    while(S[P[b]].top()!=b)
                    {
                        reset(S[P[b]].top());
                        S[P[b]].pop();
                    }

                    //S[P[b]].pop();

                    //reset(b);

                    while(S[P[a]].top()!=a)
                    {
                        reset(S[P[a]].top());
                        S[P[a]].pop();
                    }
                    S[P[a]].pop();

                    S[P[b]].push(a);

                    P[a]=P[b];


                }
                else if(des=="over")
                {
                    while(S[P[a]].top()!=a)
                    {
                        reset(S[P[a]].top());
                        S[P[a]].pop();
                    }
                    S[P[a]].pop();

                    S[P[b]].push(a);

                    P[a]=P[b];
                }
            }
            else if(op=="pile")
            {
                if(des=="onto")
                {
                    while(S[P[b]].top()!=b)
                    {
                        reset(S[P[b]].top());
                        S[P[b]].pop();
                    }

                    //S[P[b]].pop();

                    //reset(b);

                    pile(a,b);

                }
                else if(des=="over")
                {
                    pile(a,b);
                }

            }
        }
        for(i=0;i<n;i++)
        {
            printf("%d:",i);
            print(i);
            printf("\n");
        }

    }
    return 0;
}
