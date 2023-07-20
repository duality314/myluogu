#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

#define MAX_N 5005
#define MAX_M 500005

using namespace std;

const int M = 80112002;
int n, m;
int _in[MAX_N], _out[MAX_N];
vector<int> bian[MAX_N];
queue<int> q;
int ans[MAX_N];
int ANS;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ++_out[x];
        ++_in[y];
        bian[x].push_back(y);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!_in[i])
        {
            ans[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        int len = bian[top].size();
        for (int i = 0; i < len; i++)
        {
            int tmp;
            tmp = bian[top][i];
            --_in[tmp];
            ans[tmp] = (ans[top] + ans[tmp]) % M;
            if (_in[tmp] == 0)
            {
                q.push(tmp);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!_out[i])
            ANS = (ANS + ans[i]) % M;
    }
    cout << ANS;
    return 0;
}