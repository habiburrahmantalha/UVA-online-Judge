#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

string s1,s2;

bool isvowel(char ch)
{
    if(ch=='a'|| ch=='e' || ch=='i' || ch=='o' || ch=='u')
        return true;
    return false;

}
bool abstract()
{
    int i;
    for(i=0;i<s1.size();i++)
    {
        if(isvowel(s1[i]) && isvowel(s2[i]))
            continue;
        else if(s1[i]!=s2[i])
            return false;

    }
    return true;
}
int main()
{
    int tc;
    scanf("%d\n",&tc);

    while(tc--)
    {
        getline(cin,s1);
        getline(cin,s2);

        if(s1.size()!=s2.size())
            printf("No\n");
        else
        {
            if(abstract())
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}
