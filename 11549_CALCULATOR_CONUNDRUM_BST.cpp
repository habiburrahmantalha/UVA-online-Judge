//Problem Type :    cycle finding
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

long long mx,n,k;



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

bool find_k(BST *node)
{
    if(node->data==k)
        return true;
    else if(node->data==-1)
    {
        node->data=k;
        return false;
    }
    else if(node->data>k)
    {
        if(node->left==NULL)
        {
            node->left=(BST *)malloc(sizeof(BST));
            initialize(node->left);
        }
        return find_k(node->left);
    }
    else
    {
        if(node->right==NULL)
        {
            node->right=(BST *)malloc(sizeof(BST));
            initialize(node->right);
        }
        return find_k(node->right);

    }
}
long long first_n()
{
    char a[30];
    sprintf(a,"%lld",k);
    a[n]=0;
    return atol(a);
}
void cycle_find(BST *root)
{
    mx=k;
    while(!find_k(root))
    {
        k*=k;
        k=first_n();
        mx=max(mx,k);
    }
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        BST *root;
        root=(BST *)malloc(sizeof(BST));
        initialize(root);

        scanf("%lld %lld",&n,&k);
        cycle_find(root);
        printf("%lld\n",mx);

    }
    return 0;
}
