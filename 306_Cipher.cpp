#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int n,c[205],d[205][205];
vector<int> v[205];
void decode()
{
    int i=1,j,in;
    for(i=0;i<n;i++)
    {
        j=i;
        //v[i].push_back(0);
        while(1)
        {
            v[i].push_back(c[j]);
            printf("%d ",c[j]);
            j=c[j];
            if(c[i]==c[j])
                break;
        }
        printf("\n");
    }
}

int main()
{
    int i,k;
    string str;
    char A[210],B[210];
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&c[i]);
            c[i]--;
        }
        decode();
        while(scanf("%d",&k) && k)
        {
            getline(cin,str);
            for(i=0;i<str.size();i++)
            {
                B[v[i][k%v[i].size()]]=str[i];
            }
            cout<<B;
        }
    }
    return 0;
}
