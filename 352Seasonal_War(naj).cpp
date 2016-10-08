#include <stdio.h>
int n;
char a[28][28];
int X[]={-1,1,0,0,-1,1,1,-1};
int Y[]={0,0,-1,1,1,1,-1,-1};

int check(int s,int p)
{
if(s<0||s>=n||p<0||p>=n)
return 0;
else return 1;
}

void dfs (int x, int y)
{
int s,p,i;
for(i=0;i<8;i++)
{
s=x+X[i];
p=y+Y[i];
if(check(s,p) && a[s][p]=='1')
{
a[s][p]='0';
dfs(s,p);
}
}
}

int main ()
{
int cases=1,i,j;
while(scanf("%d",&n)!=EOF)
{
for(i=0;i<n;i++)
scanf ("%s",a[i]);
int count=0;
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
if(a[i][j]=='1')
{
dfs(i,j);
count++;
}
}
}
printf ("Image number %d contains %d war eagles.\n",cases++,count);
}
return 0;
}
