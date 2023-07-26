#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[200005];
int sortarr[200005];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sortarr[i] = arr[i];
    }
    sort(sortarr, sortarr + n);
    for (int i = 0; i < n; i++)
    {
        if ((sortarr[i] % 2) != arr[i] % 2)
        {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
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