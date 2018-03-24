#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

string compute(string str);

int index;
int brackets;
int number[300][30];

int main()
{
    string line;
    while(cin >> line && line != "\n")
    {
        index = 0;
        brackets = 0;
        memset(number, 0, sizeof(number));

        string ans = compute(line);
        cout << ans << endl;
    }


    return 0;
}

string compute(string str)
{
    int num = 0;
    string ss;
    while(index<str.length())
    {
        if(str[index] == '{')
        {
            while(str[index]!='}')
            {
                number[num][str[index]-65] = 1;
                index++;
            }
            num++;
        }
        if(str[index] == '+' || str[index] == '-' || str[index] == '*')
        {
            ss+=str[index];
        }
    }



}
