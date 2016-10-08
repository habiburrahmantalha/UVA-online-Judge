
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    //freopen("in.txt","r",stdin);
    char ch;

    char puncislower[]={"`-=[];',./"};
    char punctolower[]={"`[];=k-vg'"};
    char puncisupper[]={"~!@#$%^&*()_+{}|:<>"};
    char punctoupper[]={"~!@#QJLMFP?{}:+|KVG"};
    char uppercase[]={"&IX(^AEHUTDCWNYB$>*OS<%ZR)"};
    char lowercase[]={"7ix96aehutdcwnyb4.8os,5zr0"};
    char digit[]={"/123qjlmfp"};

    while(scanf("%c",&ch)!=EOF)
    {
        if(ch==' ' || ch=='\n')
        printf("%c",ch);
        else if(islower(ch))
        printf("%c",lowercase[ch-'a']);
        else if(isupper(ch))
        printf("%c",uppercase[ch-'A']);
        else if(isdigit(ch))
        printf("%c",digit[ch-'0']);
        else
        {
            bool f=false;
            if(ch=='"')
            printf("_");
            else if(ch=='?')
            printf("%c",34);
            else if(ch==92)
            printf("\\");
            else
            {
                for(int i=0;i<11;i++)
                {
                    if(puncislower[i]==ch)
                    {
                        printf("%c",punctolower[i]);
                        break;
                        f=true;
                    }
                }
                if(f==false)
                for(int i=0;i<19;i++)
                {
                    if(puncisupper[i]==ch)
                    {
                        printf("%c",punctoupper[i]);
                        break;
                    }

                }
            }
        }

    }
    return 0;
}
