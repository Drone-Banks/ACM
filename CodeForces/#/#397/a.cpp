#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a, b;
string flight, home;

int main() {
	scanf("%d", &n);
	cin >> home;
	a = 0; b = 0;
	for (; n--;) 
	{
		cin >> flight;
		string from = "", to = "";
		for (int i = 0; i < 3; i++)
			from += flight[i];
		if (from == home)
			++a;
		else
			++b;
	}
	if (a == b)
		printf("home\n");
	else
		printf("contest\n"); 
}

