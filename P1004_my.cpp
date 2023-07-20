#include <cstdio>
#include <iostream>

#define MAX_N 20
int f[MAX_N][MAX_N];
int n;

int dfs(int i, int j)
{
    if (f[i][j])
        return f[i][j];
    if (i == 0)
        return 1;
    if (j > 0)
        f[i][j] += dfs(i, j - 1);

    f[i][j] += dfs(i - 1, j + 1);
    return f[i][j];
}

using namespace std;

int main()
{
    cin >> n;
    cout << dfs(n, 0);
    return 0;
}