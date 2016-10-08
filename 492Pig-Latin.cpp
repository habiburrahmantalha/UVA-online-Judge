#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<string>
#include<iostream>
#include <sstream>


using namespace std;

bool is_vowel(char c)
{
    c=tolower(c);
    return ( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}


void change(string word)
{
    if(is_vowel(word[0]))
    {
        word+="ay";
        cout<<word;
    }

    else
    {

        word+=word[0];
        word.erase(0,1);
        word+="ay";
        cout<<word;
    }
}

int main()
{
    string line,word;
    while(getline(cin,line))
    {
        word="";
        line+="\n";
        for(int i=0;i<line.size();i++)
        {
            if(isalpha(line[i]))
            word+=line[i];
            else
            {
                if(word.size()>0)
                    change(word);

                printf("%c",line[i]);
                word="";

            }
        }
    }
    return 0;
}

