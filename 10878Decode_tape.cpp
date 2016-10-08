#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

int main()
{
    string x;
    getline(cin,x);
    while(1)
    {
        getline(cin,x);
        //cout<<x;
        if(x[0]=='_')
        break;
        if(x=="|  o  .   |")
        printf(" ");
        else if(x=="|  o o.oo |")
        printf(".");
        else if(x=="|    o. o |")
        printf("\n");
        else if(x=="| o   .  o|")
        printf("A");
        else if(x=="| o   . o |")
        printf("B");
        else if(x=="| o   . oo|")
        printf("C");
        else if(x=="| o   .o  |")
        printf("D");
        else if(x=="| o   .o o|")
        printf("E");
        else if(x=="| o   .oo |")
        printf("F");
        else if(x=="| o   .ooo|")
        printf("G");
        else if(x=="| o  o.   |")
        printf("H");
        else if(x=="| o  o.  o|")
        printf("I");
        else if(x=="| o  o. o |")
        printf("J");
        else if(x=="| o  o. oo|")
        printf("K");
        else if(x=="| o  o.o  |")
        printf("L");
        else if(x=="| o  o.o o|")
        printf("M");
        else if(x=="| o  o.oo |")
        printf("N");
        else if(x=="| o  o.ooo|")
        printf("O");
        else if(x=="| o o .   |")
        printf("P");
        else if(x=="| o o .  o|")
        printf("Q");
        else if(x=="| o o . o |")
        printf("R");
        else if(x=="| o o . oo|")
        printf("S");
        else if(x=="| o o .o  |")
        printf("T");
        else if(x=="| o o .o o|")
        printf("U");
        else if(x=="| o o .oo |")
        printf("V");
        else if(x=="| o o .ooo|")
        printf("W");
        else if(x=="| o oo.   |")
        printf("X");
        else if(x=="| o oo.  o|")
        printf("Y");
        else if(x=="| o oo. o |")
        printf("Z");
        else if(x=="| oo  .  o|")
        printf("a");
        else if(x=="| oo  . o |")
        printf("b");
        else if(x=="| oo  . oo|")
        printf("c");
        else if(x=="| oo  .o  |")
        printf("d");
        else if(x=="| oo  .o o|")
        printf("e");
        else if(x=="| oo  .oo |")
        printf("f");
        else if(x=="| oo  .ooo|")
        printf("g");
        else if(x=="| oo o.   |")
        printf("h");
        else if(x=="| oo o.  o|")
        printf("i");
        else if(x=="| oo o. o |")
        printf("j");
        else if(x=="| oo o. oo|")
        printf("k");
        else if(x=="| oo o.o  |")
        printf("l");
        else if(x=="| oo o.o o|")
        printf("m");
        else if(x=="| oo o.oo |")
        printf("n");
        else if(x=="| oo o.ooo|")
        printf("o");
        else if(x=="| ooo .   |")
        printf("p");
        else if(x=="| ooo .  o|")
        printf("q");
        else if(x=="| ooo . o |")
        printf("r");
        else if(x=="| ooo . oo|")
        printf("s");
        else if(x=="| ooo .o  |")
        printf("t");
        else if(x=="| ooo .o o|")
        printf("u");
        else if(x=="| ooo .oo |")
        printf("v");
        else if(x=="| ooo .ooo|")
        printf("w");
        else if(x=="| oooo.   |")
        printf("x");
        else if(x=="| oooo.  o|")
        printf("y");
        else if(x=="| oooo. o |")
        printf("z");

    }
}
