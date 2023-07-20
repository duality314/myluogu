#include <iostream>

using namespace std;

int n, m;

char mp[105][105];
char ans[105][105];
int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '*')
            {
                ans[i][j] = '*';
            }
            else
                ans[i][j] = '0';
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (mp[i][j] == '*')
            {
                for (int x = 0; x < 8; x++)
                    for (int y = 0; y < 8; y++)
                    {
                        if (ans[i + dx[x]][j + dy[y]] != '*')
                            ans[i + dx[x]][j + dy[y]]++;
                    }
            }
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << ans[i][j];
        cout << endl;
    }
    return 0;
}