#include<stdio.h>
#include<map>
#include<string>

using namespace std;

int main()
{
    map<string,string> mp;
    mp["HELLO"]="ENGLISH";
    mp["HOLA"]="SPANISH";
    mp["HALLO"]="GERMAN";
    mp["BONJOUR"]="FRENCH";
    mp["CIAO"]="ITALIAN";
    mp["ZDRAVSTVUJTE"]="RUSSIAN";
    char s[20];
    int t=1;
    while(scanf("%s",s))
    {
        if(s[0]=='#')
            break;
        if(mp[s]=="")
            printf("Case %d: UNKNOWN\n",t++);
        else
        printf("Case %d: %s\n",t++,mp[s].c_str());
    }
    return 0;
}
