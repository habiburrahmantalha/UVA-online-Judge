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

int A[510][510];
struct ST
{
    int mx;
    int mn;
};
ST T[510*1000];
int C=1;
int devide(int a,int b)
{
    int c=a+b;
    if(c&1)
        return (c-1)/2;
    else
        return c/2;
}
void build_tree(int in,int x1,int y1,int x2,int y2)
{
    if(x1>x2 || y1>y2)
    {
        T[in].mx=-1000000;
        T[in].mn=1000000;
        return;
    }
    if(x1==x2 && y1==y2)
    {
        T[in].mx=T[in].mn=A[x1][y1];
        //cout<<T[in].mx<<" "<<T[in].mn<<endl;
        return;
    }

    int a=4*in-2;
    int b=a+1;
    int c=b+1;
    int d=c+1;
    int mx=devide(x1,x2);
    int my=devide(y1,y2);

    build_tree(a,x1,y1,mx,my);
    build_tree(b,x1,my+1,mx,y2);
    build_tree(c,mx+1,y1,x2,my);
    build_tree(d,mx+1,my+1,x2,y2);

    T[in].mx=max(T[a].mx,max(T[b].mx,max(T[c].mx,T[d].mx)));
    T[in].mn=min(T[a].mn,min(T[b].mn,min(T[c].mn,T[d].mn)));
    //cout<<T[in].mx<<" "<<T[in].mn<<endl;

}
void change(int in,int x,int y,int x1,int y1,int x2,int y2)
{
    if(x1>x2 || y1>y2)
    {
        T[in].mx=-1000000;
        T[in].mn=1000000;
        return;
    }

    if(x==x1 && x1==x2 && y==y1 && y1==y2)
    {
        T[in].mx=T[in].mn=A[x][y];
        return ;
    }
    int a=4*in-2;
    int b=a+1;
    int c=b+1;
    int d=c+1;
    int mx=devide(x1,x2);
    int my=devide(y1,y2);

    if(x>=x1 && x<=mx && y>=y1 && y<=my)
        change(a,x,y,x1,y1,mx,my);
    else if(x>=x1 && x<=mx && y>=my+1 && y<=y2)
        change(b,x,y,x1,my+1,mx,y2);
    else if(x>=mx+1 && x<=x2 && y>=y1 && y<=my)
        change(c,x,y,mx+1,y1,x2,my);
    else
        change(d,x,y,mx+1,my+1,x2,y2);

    T[in].mx=max(T[a].mx,max(T[b].mx,max(T[c].mx,T[d].mx)));
    T[in].mn=min(T[a].mn,min(T[b].mn,min(T[c].mn,T[d].mn)));


}
ST query(int in,int x1,int y1,int x2,int y2,int qx1,int qy1,int qx2,int qy2)
{
    cout<<T[in].mx<<" "<<T[in].mn<<endl;
     if(x1>x2 || y1>y2)
    {
        ST temp;
        temp.mn= 1000000;
        temp.mx=-1000000;
        return temp;
    }

    if(x1>=qx1 && y1>=qy1 && x2<=qx2 && y2<=qy2)
        return T[in];
    else
    {
        int a=4*in-2;
        int b=a+1;
        int c=b+1;
        int d=c+1;
        int mx=devide(x1,x2);
        int my=devide(y1,y2);

        ST d1,d2,d3,d4,dr;
        d1.mx=d2.mx=d3.mx=d4.mx=-1000000;
        d1.mn=d2.mn=d3.mn=d4.mn=1000000;

        if( (qx1<=mx && qy1<=my) || (qx2<=mx && qy2<=my) )
        {
            d1=query(a,x1,y1,mx,my,qx1,qy1,qx2,qy2);
        }
        if( (qx1>=x1 && qy1>my && qx1<=mx && qy1<=y2) || (qx2>=x1 && qy2>my && qx2<=mx && qy2<=y2) )
        {
            d2=query(b,x1,my+1,mx,y2,qx1,qy1,qx2,qy2);
        }
        if( (qx1>mx && qy1>=y1 && qx1<=x2 && qy1<=my) || (qx2>mx && qy2>=y1 && qx2<=x2 && qy2<=my) )
        {
            d3=query(c,mx+1,y1,x2,my,qx1,qy1,qx2,qy2);
        }
        if( (qx1>mx && qy1>my) || (qx2>mx && qy2>my) )
        {
            d4=query(d,mx+1,my+1,x2,y2,qx1,qy1,qx2,qy2);
        }


        dr.mx=max(d1.mx,max(d2.mx,max(d3.mx,d4.mx)));
        dr.mn=min(d1.mn,min(d2.mn,min(d3.mn,d4.mn)));
        //cout<<dr.mx<<""<<dr.mn<<endl;
        return dr;
    }

}
int n,m;
void print(int a,int b,int c,int d)
{
    for(int i=a;i<=c;i++)
    {
        for(int j=b;j<=d;j++)
            cout<<A[i][j]<<" ";

        cout<<endl;
    }
}
int main()
{
    //freopen("out.txt","w",stdout);
    int i,j,x1,x2,y1,y2,c,q;
    char str[5];
    scanf("%d %d",&n,&m);
    {
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&A[i][j]);

        build_tree(1,0,0,n-1,m-1);

        scanf("%d",&q);
        while(q--)
        {
            scanf("%s",&str);
            if(str[0]=='q')
            {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                print(x1-1,y1-1,x2-1,y2-1);
                ST res=query(1,0,0,n-1,m-1,x1-1,y1-1,x2-1,y2-1);
                printf("%d %d\n",res.mx,res.mn);

            }
            else
            {
                scanf("%d %d %d",&x1,&y1,&c);
                A[x1-1][y1-1]=c;
                change(1,x1-1,y1-1,0,0,n-1,m-1);
            }
        }
    }
    return 0;
}
