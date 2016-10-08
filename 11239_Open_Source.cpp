//Problem Type : map
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
struct signup
{
    string str;
    int size;
};
bool cmp(signup a,signup b)
{
    if(a.size==b.size)
        return a.str<b.str;
    return a.size>b.size;
}
int main()
{
    char x[1010];
    int i;
    vector<signup>project;
    map<string,int>student;
    map<string,int> :: iterator it;
    vector<map<string,int> > signups;

    while(gets(x))
    {

        if(x[0]=='0')
        break;
        while(1)
        {
            if(x[0]=='1')
            break;
            signup y;
            project.push_back(y);
            project[project.size()-1].str=x;
            project[project.size()-1].size=0;
            map<string,int>m;
            while(gets(x))
            {
                if(isupper(x[0]) || x[0]=='1')
                break;
                m[x]=1;
            }
            project[project.size()-1].size=m.size();
            for(it=m.begin();it!=m.end();it++)
            student[it->first]++;
            signups.push_back(m);

        }
        for(it=student.begin();it!=student.end();it++)
        {
            if(it->second>1)
            {
                for(i=0;i<project.size();i++)
                {
                    if(signups[i][it->first])
                    project[i].size--;
                }
            }
        }

        sort(project.begin(),project.end(),cmp);
        for(i=0;i<project.size();i++)
        printf("%s %d\n",project[i].str.c_str(),project[i].size);

        project.clear();
        student.clear();
        signups.clear();
    }
    return 0;
}
