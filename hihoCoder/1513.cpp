#include<bitset>
#include<iostream>
#include<vector>
#include<algorithm>
using std::bitset;
using namespace std;
int sort_now;
#define LEN 30000

int main()
{
	sort_now = 0;
	int n;
	cin >> n;
	bitset<LEN> *info = new bitset<LEN>[n];
	for (int i = 0; i < n; i++)
	{
		info[i].set();
	}
	int sort[5][LEN];
	int x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> x;
			sort[j][x-1] = i;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		bitset<LEN> test;
		info[sort[i][0]] = info[sort[i][0]] & test;
		for (int j = 1; j < n; j++)
		{
			test[sort[i][j-1]] = 1;
			info[sort[i][j]] = info[sort[i][j]] & test;
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << info[i].count() << endl;
	}
	//cin >> n;
	return 0;
}

