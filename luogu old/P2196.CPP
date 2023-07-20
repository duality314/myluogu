#include <iostream>
#include <cstdio>

using namespace std;

int N;
int boom[25];
bool mmap[25][25];
int maxboom;
int dist[25];
int dp[25];
// dfs

void dfs();

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> boom[i];
    for (int i = 1; i < N; i++)
        for (int j = i + 1; j <= N; j++)
            cin >> mmap[i][j];

    // dist init
    for (int i = 1; i <= N; i++)
        dist[i] = -1;
    // dp
    dp[N] = boom[N];
    for (int i = N; i > 0; i--)
    {
        dp[i] = boom[i];
        for (int j = i + 1; j <= N; j++)
        {
            if (mmap[i][j] == 0)
                continue;
            if (dp[i] < boom[i] + dp[j])
            {
                dp[i] = boom[i] + dp[j];
                dist[i] = j;
            }

            // dp[i] = max(dp[i], boom[i] + dp[j]);
        }
    }
    int re = 0;
    int index = 0;
    for (int i = 1; i <= N; i++)
        if (re < dp[i])
        {
            index = i;
            re = dp[i];
        }
    // re = re > dp[i] ? re : dp[i];
    do
    {
        cout << index << " ";
        index = dist[index];
    } while (index != -1);
    cout << endl;
    cout << re;
    return 0;
}