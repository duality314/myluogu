#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

#define MAXN 1005
#define MAX_N 1005
#define ll unsigned long long

using namespace std;

string f[MAX_N][MAX_N];

void show(string a)
{
    // cout << a << endl;
    return;
}
string _add(string a, string b) // 高精度相加 (为底下a或b为负数相减做铺垫)这个都会吧。
{
    string sum;
    int na[MAXN] = {0}, nb[MAXN] = {0}, ans[MAXN + 1] = {0}; // 初始化
    // 翻转
    for (int i = a.size(); i > 0; i--)
        na[i] = a[a.size() - i] - '0';
    for (int i = b.size(); i > 0; i--)
        nb[i] = b[b.size() - i] - '0';

    int maxl = max(a.size(), b.size());

    for (int i = 1; i <= maxl; i++)
    {
        ans[i + 1] = (ans[i] + na[i] + nb[i]) / 10;
        ans[i] = (ans[i] + na[i] + nb[i]) % 10;
    } // 相加

    if (ans[maxl + 1] != 0)
        sum += "1"; // 特判 防止最大位进位

    for (int i = maxl; i > 0; i--)
        sum += ans[i] + '0';

    return sum;
}

int main()
{
    int m, n;
    cin >> m >> n;
    // f[m][m] = 0;
    f[m][m + 1] = "1";
    f[m][m + 2] = "2";
    for (int i = m + 3; i <= n; i++)
    {
        f[m][i] = _add(f[m][i - 1], f[m][i - 2]); // f[m][i - 1] + f[m][i - 2];
        //cout << i << ":" << f[m][i] << endl;
    }
    cout << f[m][n];

    return 0;
}
/*
    1 2 3
    1 2 3 4 5
    1 2 3 5
    1 2 4
    1 2 4 5
    1 3
    1 3 4 5
    1 3 5

*/