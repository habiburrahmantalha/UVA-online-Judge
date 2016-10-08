//Problem Type :
//Time :
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


int main()
{
    int tc,t=1,i,j,c,M,N;
    char trouble_maker[5][5]={"Ja", "Sam", "Sha", "Sid", "Tan"};
    char name_on_list[5];
    map<string,queue<string> > list;
    map<string,int> single;
    string name,name2;

    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&M,&N);
        cin>>name;
        for(i=0;i<5;i++)
        {
            scanf("%d",&c);
            for(j=0;j<c;j++)
            {
                scanf("%s",&name_on_list);
                list[trouble_maker[i]].push(name_on_list);
            }
        }
        while(N>0)
        {
            if(N-M<0)
            single[name]+=N;
            else
            single[name]+=M;

            N-=M;
            name2=list[name].front();
            list[name].pop();
            list[name].push(name2);
            name=name2;
            N-=2;
            //cout<<N<<name<<endl;
        }
        printf("Case %d:\n",t++);
        for(i=0;i<5;i++)
        cout<<trouble_maker[i]<<" "<<single[trouble_maker[i]]<<endl;

        single.clear();
        list.clear();
    }
    return 0;
}
