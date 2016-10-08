#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;


int main()
{
    int tc,i;
    string str;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>str;
        sort(str.begin(),str.end());

        do {
            cout<<str<<endl;
        } while ( next_permutation (str.begin(),str.end()) );
        cout<<endl;
    }
    return 0;
}

