#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <math.h>
#include <iomanip>
#include <queue>

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

const int mxn = 2e5+5;
vector<int> it[mxn], a, b, c;
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    //it[2].pb(4); it[3].pb(5);
    //merge(it[2].begin(), it[2].end(), it[3].begin(), it[3].end(), it[1].begin());
    //for (int i : it[1]) cout << i << ' ';
    a.pb(1); b.pb(2);
    merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    for (int i : c) cout << i << ' ';
}











