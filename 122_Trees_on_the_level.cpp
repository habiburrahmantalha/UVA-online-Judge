#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
using namespace std;
#include<map>

map<int,int>T;
int nod,total;

void insert(int n,string str,int in,int i)
{
    if(str.size()==0)
    {
        T[i]=n;
        return;

    }
    if(str.size()==in)
    {
        T[i]=n;
        return;
    }
    if(str[in]=='L')
    {
        insert(n,str,in+1,i*2+1);

    }
    if(str[in]=='R')
    {
        insert(n,str,in+1,i*2+2);
    }
}
void print()
{
    map<int,int>::iterator it;
    for(it=T.begin();it!=T.end();it++)
    {
        printf("%d",(*it).second);
        break;
    }
    it++;
    for(;it!=T.end();it++)
    {
        if((*it).second)
        printf(" %d",(*it).second);

    }
    printf("\n");

}
void traverse(int in)
{
    if(T[in]==0)
    return;
    nod++;
    traverse(in*2+1);
    traverse(in*2+2);

}
int main()
{
    int n,in,i;
    string m,str,x;

    nod=total=0;
    while(cin>>x)
    {


        if(x=="()")
        {
            traverse(0);
            //printf("%d %d\n",nod,total);

            if(nod!=total || nod==0)
            printf("not complete\n");
            else
            print();

            T.clear();
            nod=total=0;
        }
        else
        {

            total++;

            m="";
            for(i=0;i<x.size();i++)
            if(isdigit(x[i]))
            m+=x[i];

            n=atoi(m.c_str());

            str="";

            for(i=0;i<x.size();i++)
            if(x[i]=='L')
            str+="L";
            else if(x[i]=='R')
            str+="R";

            insert(n,str,0,0);
            //cout<<n<<str<<endl;

        }


    }
    return 0;
}
