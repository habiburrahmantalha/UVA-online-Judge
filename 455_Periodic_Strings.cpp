#include<stdio.h>
#include<string.h>
#include<string>
#include<map>
#include<iostream>
using namespace std;

int main()
{
    int tc,i,j;
    bool NL=false,f;
    string str,check,temp;
    int c;
    scanf("%d",&tc);
    while(tc--)
    {
        if(NL)
        printf("\n");
        NL=true;
        cin>>str;

        for(i=1;i<=str.size();i++)
        {
            check=str.substr(0,i);
            //cout<<check;
            f=true;
            c=i;
            for(j=i;j<=str.size()-i;j+=i)
            {
                temp=str.substr(j,i);
                //cout<<"="<<temp<<endl;
                if(temp!=check)
                {
                    f=false;
                    break;
                }
                if(f)
                c+=i;


            }
            if(f && c==str.size())
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
