#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <string>
#include <queue>
#include <bitset>
using namespace std;
 
#define int long long
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; ++i)
#define FORD(i, a, b) for (int i = (a), _b = (b); i >= _b; --i)
#define REP(i, a) for (int i = 0, _a = (a); i < _a; ++i)
#define REPD(i,n) for(int i = (n)-1; i >= 0; --i)
 
#define DEBUG(X) { cerr << #X << " = " << (X) << endl; }
#define PR(A, n) { cerr << #A << " = "; FOR(_, 1, n) cerr << A[_] << ' '; cerr << endl; }
#define PR0(A, n) { cerr << #A << " = "; REP(_, n) cerr << A[_] << ' '; cerr << endl; }
 
#define sqr(x) ((x) * (x))
#define ll long long
#define double long double
typedef pair<int, int> II;
#define PI (2 * acos((double)0))
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int)(x).size())
#define ALL(a) (a).begin(), (a).end()
#define MS(a,x) memset(a, x, sizeof(a))
#define next ackjalscjaowjico
#define prev ajcsoua0wucckjsl
#define y1 alkscj9u20cjeijc
#define left lajcljascjljl
#define right aucouasocjolkjl
#define y0 u9cqu3jioajc
 
#define TWO(X) (1LL<<(X))
#define CONTAIN(S,X) ((S) & TWO(X))
 
double safe_sqrt(double x) { return sqrt(max((double)0.0, x)); }
int GI(int& x) { return scanf("%lld", &x); }
 
bool res[5011];
 
int32_t main() {
    int a, b;
    cin >> a >> b;
    if (a <= b) cout << "Impossible" << endl;
    else {
        int n = a + b;
        int good = 0, sum = 0;
        REP(x,n) {
            if (sum <= 0) good = x, sum = 0;
 
            cout << "? " << x << ' ' << good << endl;
            char response; cin >> response;
 
            if (response == 'Y') ++sum;
            else --sum;
        }
 
        REP(x,n) {
            cout << "? " << good << ' ' << x << endl;
            char response; cin >> response;
            res[x] = (response == 'Y');
        }
        cout << "! ";
        REP(i,n) cout << res[i];
        cout << endl;
    }
    return 0;
}
