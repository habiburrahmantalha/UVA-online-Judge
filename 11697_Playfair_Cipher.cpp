#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
string key,text,temp;
char T[6][6];
void encryption_key()
{
    key+="abcdefghijklmnoprstuvwxyz";
    int i,j,in,f[30];
    memset(f,0,sizeof(f));
    in=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(f[key[in]-'a']==0)
            {
                T[i][j]=key[in];
                f[key[in]-'a']=1;

            }
            else
            j--;
            in++;
        }
    }
}
string remove_space()
{
    int i;
    string str="";
    for(i=0;i<temp.size();i++)
    if(temp[i]!=' ')
    str+=temp[i];

    return str;
}
int get_row(char x)
{
    int i,j;
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    if(x==T[i][j])
    return i;

}

int get_clmn(char x)
{
    int i,j;
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    if(x==T[i][j])
    return j;

}
int main()
{
    int tc,i,r1,r2,c1,c2;
    string res;
    scanf("%d",&tc);
    getline(cin,temp);
    while(tc--)
    {
        res="";

        getline(cin,temp);
        key=remove_space();
        getline(cin,temp);
        text=remove_space();

        encryption_key();


        for(i=0;i<text.size();i+=2)
        {
            if(i+1==text.size())
            text+="x";
            else if(text[i]==text[i+1])
            text.insert(i+1,"x");

            r1=get_row(text[i]);
            r2=get_row(text[i+1]);

            c1=get_clmn(text[i]);
            c2=get_clmn(text[i+1]);

           if(r1==r2)
            {
                res+=T[r1][(c1+1)%5]-32;
                res+=T[r1][(c2+1)%5]-32;
            }
            else if(c1==c2)
            {
                res+=T[(r1+1)%5][c1]-32;
                res+=T[(r2+1)%5][c1]-32;
            }
            else
            {
                res+=T[r1][c2]-32;
                res+=T[r2][c1]-32;
            }
        }

        cout<<res<<endl;
    }
    return 0;
}
