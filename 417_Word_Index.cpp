#include<stdio.h>
#include<map>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    int i,n=1;
    char a,b,c,d,e;
    string str;
    map<string,int> mp;
    for(i=0;i<5;i++)
    {
        for(a='a';a<='z';a++)
        {
            if(i==0)
            {

                str=a;
                mp[str]=n++;
            }
            else
            {
                for(b=a+1;b<='z';b++)
                {
                    if(i==1)
                    {
                        str=a;
                        str+=b;
                        mp[str]=n++;

                    }
                    else
                    {
                        for(c=b+1;c<='z';c++)
                        {
                            if(i==2)
                            {
                                str=a;
                                str+=b;
                                str+=c;
                                mp[str]=n++;

                            }
                            else
                            {
                                for(d=c+1;d<='z';d++)
                                {
                                    if(i==3)
                                    {
                                        str=a;
                                        str+=b;
                                        str+=c;
                                        str+=d;
                                        mp[str]=n++;
                                    }
                                    else
                                    {
                                        for(e=d+1;e<='z';e++)
                                        {
                                            if(i==4)
                                            {
                                                str=a;
                                                str+=b;
                                                str+=c;
                                                str+=d;
                                                str+=e;
                                                mp[str]=n++;

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }

                }
            }
        }
    }
    while(cin>>str)
    {
        cout<<mp[str]<<endl;
    }
    return 0;
}
