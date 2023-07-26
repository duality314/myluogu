#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

long long nums[200005] = {0};
void solve()
{

    map<long long, bool> fl;
    long long n, sum;
    int num;
    cin >> n;
    int illnum = 0;
    sum = (1 + n) * n / 2;
    for (int i = 1; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] > (2E10 + 1E5))
        {
            cout << "No" << endl;
            return;
        }
        num = nums[i] - nums[i - 1];
        if (num > n)
        {
            illnum = num;
        }
        else
        {
            fl[num] = 1;
        }
    }
    if (nums[n - 1] > sum)
    {
        cout << "NO" << endl;
        return;
    }
    if (nums[n - 1] != sum)
    {
        if (fl.find(sum - nums[n - 1]) != fl.end())
        {
            cout << "Yes" << endl;
            return;
        }
        else
        {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (fl[i])
            continue;
        cout << i << " ";
        illnum -= i;
        cout << illnum << " ";
    }
    if (illnum == 0)
    {
        cout << "Yes" << endl;
        return;
    }
    else
    {
        cout << "NO" << endl;
        return;
    }
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
