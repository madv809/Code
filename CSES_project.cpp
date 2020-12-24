#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>
#include <map>

#define LL long long
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define REP(i, a, b) for (int i = a; i <= b; ++i)
#define X first
#define Y second
#define pb(a) push_back(a);
#define pii pair<int, int>
#define pLi pair<LL, int>
#define piL pair<int, LL>
#define pLL pair<LL, LL>
#define ar array

using namespace std;

const int mxn = 2e6 + 5;
const int INF = 1e9;
LL f[mxn], g[mxn], a[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    //freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);
    int n; cin >> n;
    REP(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int nn = 1;
    REP(i, 2, n) if (a[i] != a[i - 1]) a[++nn] = a[i];
    n = nn;
    f[1] = 0;
    REP(i, 2, n) if (a[i] - a[i - 1] > f[i - 1])
        f[i] = a[i] - a[i - 1] + 1;
    else if (a[i] - a[i - 1] <= f[i - 1])
        f[i] = f[i - 1] + 1;

    g[n] = 0;
    for (int i = n - 1; i >= 1; --i) if (a[i + 1] - a[i] > g[i + 1])
        g[i] = a[i + 1] - a[i] + 1;
    else if (a[i + 1] - a[i] <= g[i + 1])
        g[i] = g[i + 1] + 1;

    double res = 2*INF;
    int i = 1, j = n;
    do
    {
        double x = a[j] - a[i]; x /= 2;
        double k = max(f[i], g[j]);
        if (x < k) x += k - x;
        res = min(res, x);
        if (f[i + 1] < g[j - 1]) ++i;
        else --j;
    } while (i <= j);
    cout << fixed << setprecision(1) << res;
    /*REP(i, 1, n) cout << a[i] << ' '; cout << endl;
    REP(i, 1, n) cout << f[i] << ' '; cout << endl;
    REP(i, 1, n) cout << g[i] << ' ';*/
}
