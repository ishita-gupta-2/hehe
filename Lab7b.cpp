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

bool S()
{
    int i_old = curr;
    if(str[curr] == 'a')
    {
        advance();
        if(S())
        {
            if(str[curr] == 'b')
            {
                advance();
                if(S())
                {
                    return true;
                }
            }
        }
    }
        curr = i_old;
        if(str[curr] == 'b')
        {
            advance();
            if(S())
            {
                if(str[curr] == 'a')
                {
                    advance();
                    if(S())
                    {
                        return true;
                    }
                }
            }
        }
        curr = i_old;
        return true;
        // if(str[curr] == ' ')
        // return true;
    return false;
}


int main() 
{
    //grammar 2
    //S -> aSbS | bSaS | e
    //e -> epsilon
    
    cout<<"\nEnter strings to be parsed. Enter -1 to end.\n";
    while(true)
    {
        cin>>str;
        if(str == "e")
        {
            cout<<"SUCCESSFUL\n";
            continue;
        }
        else if(str == "-1")
        return 0;
        curr = -1;
        advance();
        cout<<((S() && isDelimiter(str[curr]))? "SUCCESSFUL\n" : "UNSUCCESSFUL\n");
    }

    return 0;
}

