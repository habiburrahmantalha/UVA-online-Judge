#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<iostream>
#include<set>
using namespace std;
/*
int cnt;

struct BST
{
    BST *left;
    BST *right;
    long long data;
};

void initialize(BST *a)
{
    a->left=NULL;
    a->right=NULL;
    a->data=-1;
}

void insert(BST *node,long long x)
{
    if(node->data==x)
        return;
    else if(node->data==-1)
    {
        node->data=x;
        cnt++;
        return ;
    }
    else if(node->data>x)
    {
        if(node->left==NULL)
        {
            node->left=(BST *)malloc(sizeof(BST));
            initialize(node->left);
        }
        insert(node->left,x);
    }
    else
    {
        if(node->right==NULL)
        {
            node->right=(BST *)malloc(sizeof(BST));
            initialize(node->right);
        }
        insert(node->right,x);

    }
}
*/
int dist[1000010];

int main()
{
    int d,x[1010],y[1010];
    int tc,t=1,n,i,j;


    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&n);
/*
        cnt=1;
        BST *root;
        root=(BST *)malloc(sizeof(BST));
        initialize(root);
*/
        d=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            for(j=0;j<i;j++)
            {
                dist[d++]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
                //insert(root,d);
            }
        }
        sort(dist,dist+d);
        printf("Case %d: %d\n",t++,unique(dist,dist+d)-dist+1);

    }
    return 0;
}
