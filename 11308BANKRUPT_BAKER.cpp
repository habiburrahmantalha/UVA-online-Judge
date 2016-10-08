#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
#include<ctype.h>
using namespace std;
struct recipe
{
    int cost;
    string name;
};
bool comp(recipe a,recipe b)
{
    if ( a.cost == b.cost) return a.name < b.name;
    else return a.cost < b.cost;
}

int main()
{

    map<string,int>ingredient;
    //map<string,int>recipes;
    //map<string,int> :: iterator it;
    string name,title;
    int i,j,m,n,b,x,n_i,tc,cost,res;

    bool p;

    cin>>tc;

    while(tc--)
    {
        ingredient.clear();
        //recipes.clear();

        getchar();
        getline(cin,title);

        for(i=0;i<title.size();i++)
        {
            title[i]=toupper(title[i]);
        }
        cin>>m>>n>>b;

        for(i=0;i<m;i++)
        {
            cin>>name>>cost;
            ingredient[name]=cost;
        }
        recipe recipes[n];
        for(i=0;i<n;i++)
        {
            getchar();
            getline(cin,recipes[i].name);
            cin>>n_i;
            res=0;

            for(j=0;j<n_i;j++)
            {
                cin>>name>>x;
                res+=ingredient[name]*x;
            }
            recipes[i].cost=res;
        }
        sort(recipes,recipes+n,comp);
        cout<<title<<endl;
        p=false;
        //for(it=recipes.begin();it!=recipes.end();++it)
        for(i=0;i<n;i++)
        {
            if(recipes[i].cost<=b)
            {
                cout<<recipes[i].name<<endl;
                p=true;
            }
        }
        if(p==false)
        cout<<"Too expensive!"<<endl;
        cout<<endl;
    }
    return 0;
}
