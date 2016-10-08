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
    int tc,i,y,z,w,t=1;

    char x;
    vector<string>pile;
    string card;

    scanf("%d",&tc);
    while(tc--)
    {
        for(i=0;i<52;i++)
        {
            cin>>card;
            pile.push_back(card);
        }
        reverse(pile.begin(),pile.end());
        w=0;
        for(i=0;i<3;i++)
        {
            //cout<<pile[25]<<endl;
            x=pile[25][0];
            if(x=='A' || x=='K' || x=='Q' || x=='J' || x=='T')
                y=10;
            else
                y=x-'0';
            w+=y;
            z=10-y;
            //cout<<z<<endl;
            pile.erase(pile.begin()+24);
            pile.erase(pile.begin()+24,pile.begin()+24+z);
            //cout<<pile.size()<<endl;;
        }
        reverse(pile.begin(),pile.end());
        printf("Case %d: ",t++);
        cout<<pile[w-1]<<endl;
        pile.clear();
    }
    return 0;
}
