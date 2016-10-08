
#include<string.h>
#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    string line,word;
    int count,i;
    int x[31];
    memset(x,0,sizeof(x));
    while(getline(cin,line))
    {
        if(line=="#")
        {
            for(i=1;i<31;i++)
            if(x[i]>0)
            printf("%d %d\n",i,x[i]);

            printf("\n");
            memset(x,0,sizeof(x));
        }
        else
        {
            if(line[line.size()-1]=='-')
            {
                getline(cin,word);
                line+=word;
            }
            word="";
            line+="\n";

            for(i=0;i<line.size();i++)
            {
                if(isalpha(line[i]) || line[i]=='-' || line[i]==39)
                {
                    if(isalpha(line[i]))
                    word+=line[i];
                }
                else
                {
                    x[word.size()]++;
                    word="";
                }
            }
        }

    }
    return 0;
}

