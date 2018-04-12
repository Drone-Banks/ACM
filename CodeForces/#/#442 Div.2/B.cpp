#include<bits/stdc++.h>
#define MaxN 300005
using namespace std;


string name[5] = {"Danil", "Olya", "Slava", "Ann", "Nikita"};

string input;

int main()
{
    while(cin >> input)
    {
        int cnt = 0;
        for(int i=0;i<5;i++)
        {
            string::size_type pos = 0; 
            while( ( pos=input.find(name[i], pos) ) != string::npos ) {
                cnt++;
                pos++;
                // cout << i << ", " <<  pos << endl;
                if(cnt>1) break;
            }
            if(cnt>1) break;
        }
        // cout << cnt << endl;
        if(cnt==1) cout << "Yes\n";
        else cout << "No\n";
    }
}