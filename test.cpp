#define LL long long
#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include <vector>
#include <math.h>

using namespace std;
const LL INF = 100000000009;
pair <int, int> a[100001];
int n;

bool cmp (pair <int, int> a, pair <int, int> b)
{
    return (atan2(a.first, a.second) < atan2(b.first, b.second));
}

int main()
{
    //freopen("D:\\test.txt", "r", stdin);
    //freopen("D:\\test2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d%d", a[i].first, a[i].second);
    sort(a + 1, a + n + 1, cmp);
    int j = n - 1;
    LL sumx = 0, sumy = 0, ans = -INF, res = -INF;
    while (j) a[++n] = a[j--];
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < n; ++j)
        {
            sumx += a[i + j].first;
            sumy += a[i + j].second;
            if (sumx*sumx + sumy*sumy > ans) ans = sumx*sumx + sumy*sumy;
            else
            {
                sumx = 0;
                sumy = 0;
                res = max(res, ans);
                ans = -INF;
                break;
            }
        }
    printf("%lli", res);
}
