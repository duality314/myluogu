#include <iostream>
#include <cstdio>

using namespace std;

int T, M;
int times[10005], val[10005];
int dp[1005];
int main()
{
    cin >> T >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> times[i] >> val[i];
    }
    for (int i = 0; i < M; i++)
        for (int j = times[i]; j <= T; j++)
        {
            dp[j] = max(dp[j - times[i]] + val[i], dp[j]);
        }
    cout << dp[T];
    return 0;
}