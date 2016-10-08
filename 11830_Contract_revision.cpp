#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    string d,n;
    int i;
    while(cin>>d>>n)
    {
        if(d=="0" && n=="0")
            break;
        for(i=0;i<n.size();i++)
        {
            if(n[i]==d[0])
            {
                n.erase(i,1);
                i--;
            }
        }
        for(i=0;i<n.size();i++)
        {
            if(n[i]!='0')
                break;
            else
            {
                n.erase(i,1);
                i--;
            }

        }
        if(n.size()==0)
            printf("0\n");
        else
            cout<<n<<endl;
    }
    return 0;
}
