#include<stdio.h>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
#define LL long long
LL to_int(string str)
{
    if(str.size()==2)
        return (str[0]-'0')*10+(str[1]-'0');
    else
        return (str[0]-'0');
}
int main()
{
    LL tc,i,k;
    string str,s;
    vector<LL> num;
    vector<char> op;
    scanf("%lld",&tc);

    while(tc--)
    {
        cin>>str;
        str+=" ";
        s="";
        for(i=0;i<str.size();i++)
        {
            if(isdigit(str[i]))
                s+=str[i];
            else
            {
                op.push_back(str[i]);
                num.push_back(to_int(s));
                s="";
            }
        }
        vector<LL> num2(num);
        vector<char> op2(op);

        for(i=0;i<op.size();i++)
        {
            if(op[i]=='*')
            {
                num[i]=num[i]*num[i+1];
                num.erase(num.begin()+i+1);
                op.erase(op.begin()+i);
                i--;
            }
        }

        for(i=0;i<op.size();i++)
        {
            if(op[i]=='+')
            {

                num[i]=num[i]+num[i+1];
                num.erase(num.begin()+i+1);
                op.erase(op.begin()+i);
                i--;
            }
        }

        for(i=0;i<op2.size();i++)
        {
            if(op2[i]=='+')
            {

                num2[i]=num2[i]+num2[i+1];
                num2.erase(num2.begin()+i+1);
                op2.erase(op2.begin()+i);
                i--;
            }
        }
        for(i=0;i<op2.size();i++)
        {
            if(op2[i]=='*')
            {
                num2[i]=num2[i]*num2[i+1];
                num2.erase(num2.begin()+i+1);
                op2.erase(op2.begin()+i);
                i--;
            }
        }

    printf("The maximum and minimum are %lld and %lld.\n",num2[0],num[0]);
    num.clear();
    op.clear();
    }
    return 0;
}
