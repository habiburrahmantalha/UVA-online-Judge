#include<map>
#include<string>
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    string text,subs,s;

    bool f=false,ff;
    int tc,i,j;
    char s1[100],ch;

    scanf("%d",&tc);
    gets(s1);
    gets(s1);
    while(tc--)
    {
        if(f)
            printf("\n");
        text="";
        while((ch=getchar())!=10)
            text+=ch;
        subs="";
        while((ch=getchar())!=10)
            subs+=ch;
        cout<<subs<<endl<<text<<endl;

        while(1)
        {
            getline(cin,s);
            if(s.size()==0)
                break;

            for(i=0;i<s.size();i++)
            {
                ff=true;
                for(j=0;j<text.size();j++)
                {
                    if(s[i]==text[j])
                    {
                        printf("%c",subs[j]);
                        ff=false;
                        break;
                    }
                }
                if(ff)
                printf("%c",s[i]);
            }
            printf("\n");
        }
        f=true;
    }
    return 0;
}
