#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int tiles[200005];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> tiles[i];
    }
    int st = tiles[0], ed = tiles[n - 1];
    int cnt_st = 0, cnt_ed = 0;
    int i = 0, j = n - 1;
    if (st == ed)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (tiles[i] == st)
                sum++;
        }
        cout << (sum >= k ? "Yes" : "No") << endl;
        return;
    }
    while (i < j)
    {
        if (cnt_st == k && cnt_ed == k)
        {
            cout << "Yes" << endl;
            return;
        }
        if (tiles[i] == st && cnt_st != k)
            cnt_st++;
        if (cnt_st != k)
            i++;
        if (tiles[j] == ed && cnt_ed != k)
            cnt_ed++;
        if (cnt_ed != k)
            j--;
    }
    cout << "No" << endl;
}

int main()
{
    int solution_num;
    cin >> solution_num;

    for (int i = 0; i < solution_num; i++)
    {
        solve();
    }
}