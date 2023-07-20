#include <iostream>
#include <cstdio>

using namespace std;

int n, x;

long long lose[1005], win[1005], use[1005];

long long dp[1005];
int main()
{
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> lose[i] >> win[i] >> use[i];
    }
    for (int i = 0; i < n; i++)
        for (int w = x; w >= 0; w--)
        {
            if (w >= use[i])
            {
                dp[w] = max(dp[w]+lose[i], dp[w - use[i]] + win[i]);
            }
            else
                dp[w] += lose[i];
        }
    cout << 5 * dp[x];
    return 0;
}