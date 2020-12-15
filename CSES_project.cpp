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
 
const int mxn = 1e5 + 5;
pii a[mxn]; int n;
 
long double cal (long double t)
{
    long double mi, mx; mi = mx = a[1].Y*t + a[1].X;
    REP(i, 1, n)
    {
        mi = min(mi, a[i].Y*t + a[i].X);
        mx = max(mx, a[i].Y*t + a[i].X);
    }
    return (mx - mi);
}
 
int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    cin >> n;
    REP(i, 1, n) scanf("%d", &a[i].X);
    REP(i, 1, n) scanf("%d", &a[i].Y);
    long double l = 0, r = 1e10;
    REP(i, 1, 300)
    {
        long double m1 = l + (r - l)/3, m2 = r - (r - l)/3;
        if (cal(m1) > cal(m2)) l = m1;
        else r = m2;
    }
    cout << fixed << setprecision(3) << cal(l)/2;
}
