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
bool pop;
void empty(string str)
{
    //cout<<str<<endl;

    if(str.size()==0)
    pop=true;
    else
    {
        if(pop)
            return;
        int i,j,k;
        bool f=false;
        for(i=0;i<str.size();i++)
        {
            int c=1;

            for(j=i+1;j<str.size();j++)
            {
                if(str[i]==str[j])
                c++;
                else
                break;

            }
            if(c>1)
            {
                f=true;
                string t="";
                for(k=0;k<i;k++)
                t+=str[k];
                for(k=j;k<str.size();k++)
                t+=str[k];
                empty(t);
                if(pop)
                return;
            }

            i=j-1;
        }

    }

}

int main()
{
    int tc;
    string str;
    scanf("%d",&tc);
    while(tc--)
    {
        cin>>str;
        pop=false;
        empty(str);
        if(pop)
        printf("1\n");
        else
        printf("0\n");
    }
    return 0;
}
