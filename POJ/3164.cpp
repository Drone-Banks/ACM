#include <iostream>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

struct node
{
    int x,y;
}Node[110];

double wire[110][110];


int main()
{
    int NodeNumbers, WireNumbers;
    while(cin >> NodeNumbers >> WireNumbers)
    {
        for(int i=1;i<=NodeNumbers;i++)
        {
            cin >> Node[i].x >> Node[i].y;
        }
        for(int i=0;i<WireNumbers;i++)
        {
            int x,y;
            cin >> x >> y;
            wire[x][y] = (double)sqrt( (double)pow( abs(Node[x].x - Node[y].x), 2) + (double)pow( abs(Node[x].y - Node[y].y), 2) );
        }
    }
}
