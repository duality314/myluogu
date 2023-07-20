#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int sum;
int out;
int n;
int lies[15]; //  lies[i]  第i行在第 lies[i] 列

bool check(int col, int lie)
{
    for (int i = 1; i < col ; i++)
    {
        if (lie == lies[i] || (abs(lie - lies[i]) == abs(col - i)))
            return 0;
    }
    return 1;
}

void dfs(int col)
{
    if (col == n + 1)
    {
        sum++;
        if (out < 3)
        {
            for (int i = 1; i <= n; i++)
                cout << lies[i] << " ";
            cout << endl;
        }
        out++;
        return;
    }

    for (int lie = 1; lie <= n; lie++)
    {
        if (check(col, lie))
        {
            lies[col] = lie;
            dfs(col + 1);
            lies[col] = 0;
        }
    }
}

int main()
{
    cin >> n;
    dfs(1);
    cout << sum;
    return 0;
}