#include<stdio.h>
#include<string>
#include<sstream>
#include<iostream>
#include<math.h>
#include <stdlib.h>
using namespace std;

//2147483647

int main()
{
    long double n1,n2,n3,n;
    n=2147483647;
    string s1,s2,s3;

    while(cin>>s1>>s3>>s2)
    {
        n1=atof(s1.c_str());
        n2=atof(s2.c_str());
        cout<<s1<<" "<<s3<<" "<<s2<<endl;

        if(n1>n)
            printf("first number too big\n");

        if(n2>n)
            printf("second number too big\n");

        if(s3=="+")
            n3=n1+n2;
        if(s3=="*")
            n3=n1*n2;
        if(n3>n)
            printf("result too big\n");

    }
    return 0;
}
