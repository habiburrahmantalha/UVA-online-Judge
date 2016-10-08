#include<stdio.h>
#include<string.h>
#include<sstream>
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;

double u,i,p;

void to_u()
{
    if(i!=0)
    u=p/i;
    else
    u=0;
    printf("U=%.2lfV\n",u);
}
void to_p()
{
    p=u*i;
    printf("P=%.2lfW\n",p);
}
void to_i()
{
    if(u!=0)
    i=p/u;
    else
    i=0;
    printf("I=%.2lfA\n",i);
}
int main()
{

    int tc,t=1,j;
    bool U,I,P;

    string str;
    string s;
    scanf("%d",&tc);
    getline(cin,str);
    while(tc--)
    {
        getline(cin,str);

        U=P=I=false;
        for(j=0;j<str.size();j++)
        {

            //cout<<str[i];
            //continue;
            s="";
            if(str[j]=='U' && str[j+1]=='=')
            {
                for(;str[j]!='V';j++)
                s+=str[j];
                s+=str[j];
                //cout<<s<<endl;
                U=true;
                if(s[s.size()-2]=='k')
                {
                    u=atof(s.substr(2,s.size()-4).c_str());
                    u*=1000;
                }
                else if(s[s.size()-2]=='M')
                {
                    u=atof(s.substr(2,s.size()-4).c_str());
                    u*=1000000;
                }
                else if(s[s.size()-2]=='m')
                {
                    u=atof(s.substr(2,s.size()-4).c_str());
                    u/=1000;
                }
                else
                u=atof(s.substr(2,s.size()-3).c_str());


            }
            else if(str[j]=='I' && str[j+1]=='=')
            {

                for(;str[j]!='A';j++)
                s+=str[j];
                s+=str[j];
                //cout<<s<<endl;
                I=true;
                if(s[s.size()-2]=='M')
                {
                    i=atof(s.substr(2,s.size()-4).c_str());
                    i*=1000000;
                }
                else if(s[s.size()-2]=='m')
                {
                    i=atof(s.substr(2,s.size()-4).c_str());
                    i/=1000;
                }
                else if(s[s.size()-2]=='k')
                {
                    i=atof(s.substr(2,s.size()-4).c_str());
                    i*=1000;
                }
                else
                i=atof(s.substr(2,s.size()-3).c_str());


            }
            else if(str[j]=='P' && str[j+1]=='=')
            {
                for(;str[j]!='W';j++)
                s+=str[j];
                s+=str[j];
                //cout<<s<<endl;
                P=true;
                if(s[s.size()-2]=='m')
                {
                    p=atof(s.substr(2,s.size()-4).c_str());
                    p/=1000;
                }
                else if(s[s.size()-2]=='M')
                {
                    p=atof(s.substr(2,s.size()-4).c_str());
                    p*=1000000;
                }
                else if(s[s.size()-2]=='k')
                {
                    p=atof(s.substr(2,s.size()-4).c_str());
                    p*=1000;
                }
                else
                p=atof(s.substr(2,s.size()-3).c_str());


            }

        }
        printf("Problem #%d\n",t++);
        if(U && I)
        to_p();
        else if(U && P)
        to_i();
        else if(P && I)
        to_u();
        printf("\n");
    }
    return 0;
}
