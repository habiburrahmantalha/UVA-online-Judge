#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<map>
#include<set>
#include<algorithm>
#include<list>
using namespace std;

int main()
{
    int tc;
    double res,n;
    string tree;
    map<string,int> tree_n;
    //list<string> tree_l;
    map<string,int>::iterator it;
    bool f=false;

    scanf("%d\n",&tc);
    //getchar();
    while(tc--)
    {
        if(f)
        printf("\n");
        tree_n.clear();
        //tree_l.clear();
        n=0.0;
        while(1)
        {
            getline(cin,tree);
            if(tree.size()==0)
            break;

            tree_n[tree]++;
            //tree_l.push_back(tree);
            n++;
        }
        //tree_l.sort();
        //tree_l.unique();


         for (it=tree_n.begin(); it!=tree_n.end(); ++it)
         {
             res=(*it).second*(100/n);

             cout<<(*it).first<<" ";
             printf("%.4lf\n",res);
         }
        f=true;


    }
    return 0;
}
