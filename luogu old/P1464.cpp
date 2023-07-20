#include <iostream>
#include <cstdio>

#define MAX_N 25
#define ll long long
using namespace std;

ll w[MAX_N][MAX_N][MAX_N];

ll dfs(ll a, ll b, ll c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 20 || b > 20 || c > 20)
        return (dfs(20, 20, 20));
    else if (w[a][b][c])
        return w[a][b][c];
    else if (a < b && b < c)
        w[a][b][c] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
    else
        w[a][b][c] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
    return w[a][b][c];
}

int main()
{
    ll a, b, c;

    while (1)
    {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        printf("w(%lld, %lld, %lld) = %lld\n", a, b, c, dfs(a, b, c));
    }
    return 0;
}