

#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    string line,word;
    int count,i;
    while(getline(cin,line))
    {
        word="";
        count=0;
        line+="\n";
        for(i=0;i<line.size();i++)
        {
            if(isalpha(line[i]))
            word+=line[i];
            else
            {
                if(word.size()>0)
                count++;
                word="";
            }
        }
        printf("%d\n",count);

    }
    return 0;
}
