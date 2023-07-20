#include <iostream>
#include <cstdio>
#include <string>

#define MAXN 5000

using namespace std;

string cases[5005];

string _add(string a, string b) //高精度相加 (为底下a或b为负数相减做铺垫)这个都会吧。
{
    string sum;
    int na[MAXN] = {0}, nb[MAXN] = {0}, ans[MAXN + 1] = {0}; //初始化
    //翻转
    int alen=a.size(),blen=b.size();
    for (int i = alen; i > 0; i--)
        na[i] = a[alen - i] - '0';
    for (int i = blen; i > 0; i--)
        nb[i] = b[blen - i] - '0';

    int maxl = max(alen ,blen());

    for (int i = 1; i <= maxl; i++)
    {
        ans[i + 1] = (ans[i] + na[i] + nb[i]) / 10;
        ans[i] = (ans[i] + na[i] + nb[i]) % 10;
    } //相加

    if (ans[maxl + 1] != 0)
        sum += "1"; //特判 防止最大位进位

    for (int i = maxl; i > 0; i--)
        sum += ans[i] + '0';

    return sum;
}
int main()
{
    int n;
    cin >> n;
    cases[1] = "1";
    cases[2] = "2";
    for (int i = 3; i <= n; i++)
        cases[i] = _add(cases[i - 1], cases[i-2]);
    cout << cases[n];
    return 0;
}