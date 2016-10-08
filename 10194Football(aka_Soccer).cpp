#include<cstdio>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#include<cctype>
using namespace std;
struct team
{
    string name;
    int point,game,win,ties,loss,gd,gs,ga;
};

team T[31];

bool comp (team a,team b)
{
    if(a.point==b.point){
        if(a.win==b.win){
            if(a.gd==b.gd){
                if(a.gs==b.gs){
                    if(a.game==b.game){
                        return a.name<b.name;
                    }
                    return a.game<b.game;
                }
                return a.gs>b.gs;
            }
            return a.gd>b.gd;
        }
        return a.win>b.win;
    }
    return a.point>b.point;
}

string no_case(string str)
{
    int i;
    for(i=0;str[i]!=0;i++)
    str[i]=tolower(str[i]);
    //cout<<str<<endl;
    return str;
}

void reset(int n)
{
    for(int i=0;i<n;i++)
    {
        T[i].point=0;
        T[i].game=0;
        T[i].win=0;
        T[i].ties=0;
        T[i].loss=0;
        T[i].gd=0;
        T[i].gs=0;
        T[i].ga=0;
    }
}
int main()
{


    string title,name1,name2,x,nocase;
    int tc,n,m,g1,g2,i,j,k;

    cin>>tc;
    getchar();
    bool f=false;
    while(tc--)
    {
        if(f)
        cout<<endl;
        char g[3];

        map<string,int>t;

        getline(cin,title);
        cin>>n;
        getchar();
        for(i=0;i<n;i++)
        {
            //nocase="";
            getline(cin,T[i].name);
            t[no_case(T[i].name)]=i;
            //t[T[i].name]=i;
        }
        cin>>m;
        getchar();
        reset(n);
        for(j=0;j<m;j++)
        {
            getline(cin,x);
            name1=name2="";
            for(i=0;x[i]!='#';i++)
            name1+=x[i];
            name1=no_case(name1);
            k=0;
            memset(g,0,sizeof(g));
            for(i=i+1;x[i]!='@';i++)
            g[k++]=x[i];
            g1=atoi(g);

            k=0;
            memset(g,0,sizeof(g));
            for(i=i+1;x[i]!='#';i++)
            g[k++]=x[i];
            g2=atoi(g);

            for(i=i+1;x[i]!=0;i++)
            name2+=x[i];
            name2=no_case(name2);


            T[t[name1]].game++;
            T[t[name2]].game++;

            T[t[name1]].gs+=g1;
            T[t[name2]].gs+=g2;

            T[t[name1]].ga+=g2;
            T[t[name2]].ga+=g1;

            T[t[name1]].gd+=(g1-g2);
            T[t[name2]].gd+=(g2-g1);

            if(g1==g2)
            {
                T[t[name1]].ties++;
                T[t[name2]].ties++;

                T[t[name1]].point++;
                T[t[name2]].point++;
            }
            else if(g1>g2)
            {
                T[t[name1]].point+=3;

                T[t[name1]].win++;
                T[t[name2]].loss++;
            }
            else
            {
                T[t[name2]].point+=3;

                T[t[name1]].loss++;
                T[t[name2]].win++;
            }
        }
        sort(T,T+n,comp);
        cout<<title<<endl;
        for(i=0;i<n;i++)
        {
            j=i+1;
            cout<<j<<") "<<T[i].name<<" "<<T[i].point<<"p, "<<T[i].game<<"g ("<<T[i].win<<"-"<<T[i].ties<<"-"<<T[i].loss<<"), "<<T[i].gd<<"gd ("<<T[i].gs<<"-"<<T[i].ga<<")"<<endl;
        }
        f=true;

    }
    return 0;
}
