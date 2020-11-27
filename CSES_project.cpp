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

const int mxn = 1e5+1;
vector<LL> d[mxn];
vector<int> a[mxn], s;
vector<LL> c[mxn];

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    int n, m, k; cin >> n >> m >> k; int u, v; LL w;
    REP(i, 1, m)
    {
        cin >> u >> v >> w;
        a[u].pb(v); c[u].push_back(w);
    }

    priority_queue<ar<LL, 2>, vector<ar<LL, 2> >, greater<ar<LL, 2>>> h;
    h.push({0, 1});
    while (h.size())
    {
        u = h.top()[1]; w = h.top()[0]; h.pop();
        if (d[u].size()>=k) continue;
        d[u].push_back(w);
        for (int i = 0; i < a[u].size(); ++i)
        {
            v = a[u][i];
            h.push({w + c[u][i], v});
        }
    }
    for (int i = 0; i < k; ++i) cout << d[n][i] << ' ';
}




















