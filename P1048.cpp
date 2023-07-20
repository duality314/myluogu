#include <iostream>
#include <cstdio>

using namespace std;

int T, M;
int times[105], val[105];
int dp[1005];
int main()
{
    cin >> T >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> times[i] >> val[i];
    }
    for (int i = 0; i < M; i++)
        for (int j = T; j >= times[i]; j--)
        {
            dp[j] = max(dp[j - times[i]] + val[i], dp[j]);
        }
    cout << dp[T];
    return 0;
}