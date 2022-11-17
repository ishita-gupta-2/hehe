#include <bits/stdc++.h>
using namespace std;

string str;
int curr = -1;

bool isDelimiter(char c)
{
    return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == 0;
}

void advance()
{
    curr++;
    int len = str.length();
    if(curr >= len)  
        curr = len;
}

bool A()
{
    int i_old = curr;
    if(str[curr] == 'a')
    {
        advance();
        if(str[curr] == 'b')
        {
            advance();
            return true;
        }
        curr = i_old;
        if(str[curr] == 'a')
        {
            advance();
            return true;
        }
    }
    return false;
}

bool S()
{
    if(str[curr] == 'c')
    {
        advance();
        if(A())
        {
            if(str[curr] == 'd')
            {
                advance();
                if(isDelimiter(str[curr]))
                    return true;
            }
        }
    }
    return false;
}

int main() 
{
    //grammar 1
    //S -> cAd
    //A -> ab|a
    
    cout<<"\nEnter strings to be parsed. Enter -1 to end.\n";
    while(true)
    {
        cin>>str;
        if(str == "-1")
        return 0;
        curr = -1;
        advance();
        cout<<(S() ? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");
    }

    return 0;
}

