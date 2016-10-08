#include<iostream>
#include<map>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
    int tc,day,n,t=1;
    string sub;
    map<string,int> h;
    cin>>tc;
    while(tc--)
    {
        h.clear();
        cin>>n;
        while(n--)
        {
            cin>>sub>>day;
            h[sub]=day;
        }
        cin>>day>>sub;
        n=h[sub];
        if(day>=n && n)
        printf("Case %d: Yesss\n",t++);
        else if(day<n && day+5 >=n)
        printf("Case %d: Late\n",t++);
        else
        printf("Case %d: Do your own homework!\n",t++);
    }
    return 0;
}
