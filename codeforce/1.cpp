#include <iostream>
#include <cmath>
using namespace std;

int n, m, k, H;
int height;

void solve()
{
    int result = 0;
    cin >> n >> m >> k >> H;
    for (int i = 0; i < n; i++)
    {
        cin >> height;
        if (abs(H - height) % k == 0 && H != height && (abs(H - height) / k < m))
            result++;
    }
    cout << result << endl;
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