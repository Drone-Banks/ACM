#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
const int INF = 1000000000;
class Heap
{
	private :
		std::priority_queue < int, std::vector < int >, std::greater < int > > inc, dec;
		void BaseClear()
		{
			while (!dec.empty() && inc.top() == dec.top())
			{
				inc.pop();
				dec.pop();
			}
		}
	public :
		int top()
		{
			BaseClear();
			return inc.top();
		}
		void del(int x)
		{
			dec.push(x);
		}
		void push(int x)
		{
			inc.push(x);
		}
		void clear()
		{
			while (!inc.empty())
				inc.pop();
			while (!dec.empty())
				dec.pop();
		}
		bool empty()
		{
			BaseClear();
			return inc.empty();
		}
}Q0, Q1;
int TC, f0[200001], f1[200001], *F0 = f0 + 100000, *F1 = f1 + 100000, N, C0, C1, N0, N1, E0, E1, TAG0, TAG1;
void forward(char option)
{
	if (option == '0')
	{
		F0--;
		F0[1] = (Q1.empty() ? INF : Q1.top()) + TAG1 - TAG0;
		E0++;
		Q0.push(F0[1]);
		while (E0 >= N0)
			Q0.del(F0[E0--]);
		E1 = 0;
		Q1.clear();
	}
	else if (option == '1')
	{
		F1--;
		F1[1] = (Q0.empty() ? INF : Q0.top()) + TAG0 - TAG1;
		E1++;
		Q1.push(F1[1]);
		while (E1 >= N1)
			Q1.del(F1[E1--]);
		E0 = 0;
		Q0.clear();
	}
	else
	{
		F0--;
		F0[1] = (Q1.empty() ? INF : Q1.top()) + TAG1 - TAG0;
		E0++;
		F1--;
		F1[1] = (Q0.empty() ? INF : Q0.top()) + TAG0 - TAG1;
		E1++;
		Q0.push(F0[1]);
		Q1.push(F1[1]);
		while (E0 >= N0)
			Q0.del(F0[E0--]);
		while (E1 >= N1)
			Q1.del(F1[E1--]);
		TAG0 += C0;
		TAG1 += C1;
	}
}
int main()
{
	for (scanf("%d", &TC); TC--; )
	{
		F0 = f0 + 100000;
		F1 = f1 + 100000;
		TAG0 = TAG1 = 0;
		Q0.clear();
		Q1.clear();
		E0 = E1 = 0;
		scanf("%d%d%d%d%d", &N, &C0, &C1, &N0, &N1);
		char c = getchar();
		while (c != '0' && c != '1' && c != '?')
			c = getchar();
		if (c == '0')
		{
			F0[E0 = 1] = 0;
			Q0.push(0);
		}
		else if (c == '1')
		{
			F1[E1 = 1] = 0;
			Q1.push(0);
		}
		else
		{
			F0[E0 = 1] = C0;
			F1[E1 = 1] = C1;
			Q0.push(C0);
			Q1.push(C1);
		}
		for (int i = 1; i < N; i++)
			forward(getchar());
		int ans = 1000000001;
		if (!Q0.empty())
			ans = std::min(ans, Q0.top() + TAG0);
		if (!Q1.empty())
			ans = std::min(ans, Q1.top() + TAG1);
		printf("%d\n", ans);
	}
	return 0;
}
