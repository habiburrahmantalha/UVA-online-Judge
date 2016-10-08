#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<queue>
#include<set>
using namespace std;
#define PI 2 * acos (0.0)

bool valid(int x,int y)
{
    if(x<0 || x>=5 || y<0 || y>=5)
    return false;

    return true;
}
int main()
{
    string str,s;
    int i,j,a,b,t=1;
    vector<string>v;
    bool illigal;

    while(getline(cin,str))
    {
        if(str[0]=='Z')
        break;
        v.clear();
        v.push_back(str);
        for(i=1;i<5;i++)
        {
            getline(cin,str);
            v.push_back(str);
        }
        for(i=0;i<5;i++)
        {
            for(j=0;j<5;j++)
            if(v[i][j]==' ')
            {
                a=i;
                b=j;
                i=j=5;

            }
        }
        str="";
        while(getline(cin,s))
        {
            str+=s;
            if(s[s.length()-1]=='0')
            break;


        }
        illigal=false;
        for(i=0;i<str.size();i++)
        {
            if(str[i]=='A')
            {
                a-=1;
                if(valid(a,b))
                swap(v[a+1][b],v[a][b]);
                else
                {
                    illigal=true;
                    break;
                }
            }
            else if(str[i]=='B')
            {
                a+=1;
                if(valid(a,b))
                swap(v[a-1][b],v[a][b]);
                else
                {
                    illigal=true;
                    break;
                }
            }
            else if(str[i]=='R')
            {
                b+=1;
                if(valid(a,b))
                swap(v[a][b],v[a][b-1]);
                else
                {
                    illigal=true;
                    break;
                }
            }
            else if(str[i]=='L')
            {
                b-=1;
                if(valid(a,b))
                swap(v[a][b],v[a][b+1]);
                else
                {
                    illigal=true;
                    break;
                }
            }

        }
        if(t>1)
        cout<<endl;
        printf("Puzzle #%d:\n",t++);
        if(illigal)
        printf("This puzzle has no final configuration.\n");
        else
        {
            for(i=0;i<5;i++)
            {
                cout<<v[i][0];
                for(j=1;j<5;j++)
                cout<<" "<<v[i][j];
                cout<<endl;

            }

        }

    }
    return 0;
}
