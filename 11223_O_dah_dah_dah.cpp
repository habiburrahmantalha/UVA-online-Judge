#include<stdio.h>
#include<string>
#include<sstream>
#include<map>
#include<iostream>

using namespace std;

int main()
{
    int tc,t,i,j;
    map<string,char>mp;
    string str,s,s1;
    char ch;

    mp[".-"]='A';
    mp["-..."]='B';
    mp["-.-."]='C';
    mp["-.."]='D';
    mp["."]='E';
    mp["..-."]='F';
    mp["--."]='G';
    mp["...."]='H';
    mp[".."]='I';
    mp[".---"]='J';
    mp["-.-"]='K';
    mp[".-.."]='L';
    mp["--"]='M';
    mp["-."]='N';
    mp["---"]='O';
    mp[".--."]='P';
    mp["--.-"]='Q';
    mp[".-."]='R';
    mp["..."]='S';
    mp["-"]='T';
    mp["..-"]='U';
    mp["...-"]='V';
    mp[".--"]='W';
    mp["-..-"]='X';
    mp[".--"]='Y';
    mp["--.."]='Z';
    mp["-----"]='0';
    mp[".----"]='1';
    mp["..---"]='2';
    mp["...--"]='3';
    mp["....-"]='4';
    mp["....."]='5';
    mp["-...."]='6';
    mp["--..."]='7';
    mp["---.."]='8';
    mp["----."]='9';
    mp[".-.-.-"]='.';
    mp["--..--"]=',';
    mp["..--.."]='?';
    mp[".----."]=39;
    mp["-.-.--"]='!';
    mp["-..-."]='/';
    mp["-.--."]='(';
    mp["-.--.-"]=')';
    mp[".-..."]='&';
    mp["---..."]=':';
    mp["-.-.-."]=';';
    mp["-...-"]='=';
    mp[".-.-."]='+';
    mp["-....-"]='-';
    mp["..--.-"]='_';
    mp[".-..-."]='"';
    mp[".--.-."]='@';
    mp["S"]=' ';
    scanf("%d",&tc);
    getchar();
    for(t=1;t<=tc;t++)
    {
        if(t>1)
            printf("\n");
        getline(cin,str);


        for(i=0;i<str.size();i++)
        {
            if(str[i]==' ' && str[i+1]==' ')
            {
                str[i+1]='S';
                str.insert(i+2," ");
                j=i+3;
                while(str[j]==' ')
                {
                    str[j]='S';
                    str.insert(j+1," ");
                    j=j+2;
                }
            }

        }

        stringstream ss(str);
        printf("Message #%d\n",t);
        while(ss>>s)
        {
            printf("%c",mp[s]);
        }
        printf("\n");
    }
    return 0;
}
