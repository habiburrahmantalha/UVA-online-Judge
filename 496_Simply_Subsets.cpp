#include<stdio.h>
#include<vector>
#include<sstream>
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    set<int> a,b;
    vector<int>::iterator it;
    int x,s;
    string str;
    while(getline(cin,str))
    {

        stringstream ss(str);
        while(ss>>x)
            a.insert(x);
        getline(cin,str);
        stringstream ss1(str);
        while(ss1>>x)
            b.insert(x);

        if(a==b)
            printf("A equals B\n");
        else
        {
            //sort(a.begin(),a.end());
            //sort(b.begin(),b.end());
            if(a.size()>=b.size())
            {
                vector<int> v(a.size());
                it=set_difference (a.begin(),a.end(),b.begin(),b.end(),v.begin());
                s=int(it - v.begin());
                if(a.size()-b.size()==s)
                    printf("B is a proper subset of A\n");
                else if(s==a.size())
                    printf("A and B are disjoint\n");
                else
                    printf("I'm confused!\n");
            }
            else
            {
                vector<int> v(b.size());
                it=set_difference (b.begin(),b.end(),a.begin(),a.end(),v.begin());
                s=int(it - v.begin());
                if(b.size()-a.size()==s)
                    printf("A is a proper subset of B\n");
                else if(s==b.size())
                    printf("A and B are disjoint\n");
                else
                    printf("I'm confused!\n");
            }
        }
        a.clear();
        b.clear();
    }
    return 0;
}
