#include <iostream>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;

int main()
{
    long long  n,m,C=0;
    while(cin>>n>>m)
    {
        C++;
        list<int > box;
        for(int i=1;i<=n;i++)
        {
            box.push_back(i);
        }

        int cmd,x,y;
        bool rev = false;

        for(int i=0;i<m;i++)
        {
            cin>>cmd;
            switch (cmd)
            {
            case 1:
            {
                cin>>x>>y;
                list<int >::iterator it1 ,it2;
                it1 = find(box.begin(), box.end(), x);
                int  tmp = *it1;
                it2 = find(box.begin(), box.end(), y);
                box.insert(it2,tmp);
                box.erase(it1);
                break;
            }
            case 2:
            {
                cin>>x>>y;
                list<int >::iterator it3 , it4 ;
                it3 = find(box.begin(), box.end(), x);
                int  tmp = *it3;
                it4 = find(box.begin(), box.end(), y);;
                box.insert(++it4,tmp);
                box.erase(it3);
                break;
            }
            case 3:
            {
                cin>>x>>y;
                list<int >::iterator it5 ,it6 ;
                it5 = find(box.begin(), box.end(), x);
                it6 = find(box.begin(), box.end(), y);
                swap(*it5,*it6);
                break;
            }
            case 4:
                box.reverse();
            }
        }
        long long  sum=0;
        list<int>::iterator it = box.begin();
        bool flag=true;
        for(; it!=box.end(); ++it)
        {
        if(flag)
        {
            sum+=*it;
        }
        flag=!flag;
        }
        cout << "Case "<< C <<": "<<sum <<endl;
    }
    return 0;
}
