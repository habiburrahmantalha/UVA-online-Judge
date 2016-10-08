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

char a[25],b[25];
int T[25][25],P[25][25],l,m;
int C=1,D=2,I=3,O=0;
void print()
{
    int i,j;
    for(i=0;i<=l;i++)
    {
        for(j=0;j<=m;j++)
        {
            printf("%d ",T[i][j]);
        }
        printf("\n");
    }
}
void edit()
{
    int i,j;
    memset(T,0,sizeof(T));
    for(i=0;i<=l;i++)
    {
        T[i][0]=i;
        P[i][0]=D;
    }
    for(j=0;j<=m;j++)
    {
        T[0][j]=j;
        P[0][j]=I;
    }
    for(i=1;i<=l;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j])
            {
                T[i][j]=T[i-1][j-1];
                P[i][j]=O;
            }
            else
            {
                T[i][j]=min(min(T[i-1][j],T[i][j-1]),T[i-1][j-1])+1;

                if(T[i][j]==T[i-1][j]+1)
                P[i][j]=D;
                else if(T[i][j]==T[i][j-1]+1)
                P[i][j]=I;
                else if(T[i][j]==T[i-1][j-1]+1)
                P[i][j]=C;
            }
        }
    }
    //printf("%d\n",T[l][m]);
    //print();
}
string to_str(int x)
{
    string s="";
    while(x)
    {
        s+=(x%10+'0');
        x/=10;
    }
    if(s.size()==1)
    s+="0";
    reverse(s.begin(),s.end());

    return s;
}
void commands(int i,int j)
{
    string temp;
    vector<string>R;
    vector<int>S;
    int ii=0,dd=0;
    while(true)
    {
        if(i==0 && j==0)
        break;


        if(P[i][j]==I)
        {
            temp="I";
            temp+=b[j];
            R.push_back(temp);
            S.push_back(i);
            //printf("I%c%d",b[j],j);
            j--;

        }
        else if(P[i][j]==D)
        {
            temp="D";
            temp+=a[i];
            R.push_back(temp);
            S.push_back(i);
            //printf("D%c%d",a[i],i);
            i--;
        }
        else if(P[i][j]==C)
        {
            temp="C";
            temp+=b[j];
            R.push_back(temp);
            S.push_back(i);
            //printf("C%c%d",b[j],j);
            i--;
            j--;

        }
        else
        {
            i--;
            j--;
        }
    }
    string res="";
    reverse(R.begin(),R.end());
    reverse(S.begin(),S.end());
    dd=ii=0;
    for(i=0;i<R.size();i++)
    {
        res+=R[i];

        if(R[i][0]=='I')
        ii++;

        res+=to_str(S[i]+dd+ii);


        if(R[i][0]=='D')
        dd--;
        //cout<<S[i]<<" "<<R[i][0]<<" "<<ii<<" "<<dd<<endl;

    }
    res+="E";
    cout<<res<<endl;

}
int main()
{
    while(scanf("%s",a+1))
    {
        if(strcmp(a+1,"#")==0)
        break;
        scanf("%s",b+1);
        l=strlen(a+1);
        m=strlen(b+1);
        edit();
        commands(l,m);
    }
    return 0;
}
