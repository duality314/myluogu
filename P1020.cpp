/*#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> v;
int dp[100005];
int main()
{
    int h;
    while (cin >> h)
    {
        v.push_back(h);
    }
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[j] >= v[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
    }
    int re = 0;

    for (int i = 0; i < n; i++)
    {
        re = max(re, dp[i]);
    }
    cout << re;
    return 0;
}
*/
#include <string>
#include <iostream>
#include <cstdio>
#include <algorithm>

#define up(l, r, i) for (int i = l, END##i = r; i <= END##i; ++i)
#define dn(r, l, i) for (int i = r, END##i = l; i >= END##i; --i)

using namespace std;

typedef long long i64;
const int INF = 2147483647;
const int MAXN = 1e5 + 3;
int n, t, H[MAXN], F[MAXN];
int main()
{
    while (~scanf("%d", &H[++n]))
        ;
    --n;
    F[0] = INF;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = t + 1;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (F[m] >= H[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1; // dp[i]
        if (x > t)
            t = x;
        F[x] = H[i];
    }
    printf("%d\n", t);

    t = 0, memset(F, 0, sizeof(F)), F[0] = 0;
    up(1, n, i)
    {
        int l = 0, r = t + 1;
        while (r - l > 1)
        {
            int m = l + (r - l) / 2;
            if (F[m] < H[i])
                l = m;
            else
                r = m;
        }
        int x = l + 1;
        if (x > t)
            t = x;
        F[x] = H[i];
    }
    printf("%d\n", t);
    return 0;
}