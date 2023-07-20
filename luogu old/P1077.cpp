#include <iostream>
using namespace std;
const int maxn = 105, mod = 1000007;
int n, m, a[maxn], f[maxn];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--) // 注意，是01背包
            for (int k = 1; k <= min(a[i], j); k++)
                f[j] = (f[j] + f[j - k]) % mod;
    cout << f[m] << endl;
    return 0;
}
/*#include <cstdio>
#include <iostream>

using namespace std;

const int mod = 1E6 + 7;
int n, m, a[105], look[105][105];

int dfs(int x, int k)
{
    if (k > m)
        return 0;
    if (k == m)
        return 1;
    if (x == n)
        return 0;
    if (look[x][k])
        return look[x][k];
    int ans = 0;
    for (int i = 0; i <= a[x]; i++)
    {
        ans = (ans + dfs(x + 1, k + i)) % mod;
    }
    look[x][k] = ans;
    return ans;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << dfs(0, 0);
    return 0;
}*/
/*
#include <cstdio>
#include <iostream>

#define MOD (1E6 + 7)

using namespace std;

int n, m;
int a[105];

long long dp[105][105];//dp[i][j]

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    return 0;
}
*/