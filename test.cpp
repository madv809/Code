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
const LL INF = 100000000000009;
pair <int, int> a[200001];
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
    for (int i = 0; i < n; ++i) scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n, cmp);
    LL sumx, sumy, ans, res = -INF;
    for (int i = 1; i <= n; ++i)
    {
        sumx = 0; sumy = 0, ans = -INF;
        for (int j = 0; j < n; ++j)
        {
            sumx += a[(i + j)%n].first;
            sumy += a[(i + j)%n].second;
            if (sumx*sumx + sumy*sumy >= ans) ans = sumx*sumx + sumy*sumy;
            else
            {
                res = max(res, ans);
                break;
            }
        }
    }
    printf("%lli", res);
}
