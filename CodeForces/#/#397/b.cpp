#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, f[26];
char str[1111];

int main() {
	scanf("%s", str);
	n = strlen(str);
	memset(f, 255, sizeof(f));
	for (int i = 0; i < n; i++)
		if (f[str[i] - 'a'] == -1)
			f[str[i] - 'a'] = i;
	bool ok = true;
	int Left = -1;
	for (int i = 0; i < 26; i++)
		if (f[i] == -1)
			continue;
		else
			if (f[i] < Left)
			{
				ok = false;
				break;
			}
			else
				Left = f[i];
	int shy = 0, dhh = 0; 
	for (int i = 0; i < 26; i++)
		if (f[i] != -1)
			++shy; 
	for (int i = 0; i < 26; i++)
		if (f[i] != -1)
			++dhh;
		else
			break;
	if (dhh != shy)
		ok = false;
	if (!ok)
		printf("NO\n");
	else 
		printf("YES\n"); 
}

