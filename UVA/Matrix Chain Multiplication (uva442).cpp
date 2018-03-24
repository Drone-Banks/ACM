#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
struct matrix
{
    char ch;
    int row;
    int column;
};


int main()
{
    int n;
    cin >> n;
    matrix* mx = new matrix [n];
    for(int i=0 ;i<n;i++)
    {
        cin >> mx[i].ch >> mx[i].row >> mx[i].column;
    }
    string exp;
    while(cin>>exp)
    {
        stack<matrix> tp;
        int sum = 0;
        bool flag = true;
        int len = exp.length();
        if(len == 1)
        {
            cout << 0 <<endl;
            continue;
        }
        else
        {
            for(int i=0;i<len;i++)
            {
                if(exp[i] != '(')
                {
                    if(exp[i] == ')')
                    {
                        matrix m2 = tp.top();
                        tp.pop();
                        matrix m1 = tp.top();
                        tp.pop();
                        if(m1.column == m2.row)
                        {
                            sum += (m1.row*m1.column*m2.column);
                            matrix m3;
                            m3.ch = 'm';
                            m3.row = m1.row;
                            m3.column = m2.column;
                            tp.push(m3);
                        }
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        matrix tmp;
                        for(int j=0;j<n;j++)
                        {
                            if(exp[i] == mx[j].ch)  tmp = mx[j];
                        }
                        tp.push(tmp);
                    }
                }
            }
            if(flag) cout << sum<<endl;
            else cout << "error" <<endl;
        }
    }
    delete [] mx;
    return 0;
}
