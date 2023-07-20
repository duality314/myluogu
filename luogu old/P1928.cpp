#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string input, out;
/*
    A ACAC CBCB ACAC CBCB
    A
    [2[2AC][2CB]]
*/
string dfs(string in, bool ck, int st, int end)
{
    string x;

    int sum1 = 0, sum2 = 0;
    int len = in.length();
    bool kk = 1;
    int index1 = 0, index2 = 0;
    bool k_index = 1;
    int num = 0;
    if (ck)
    {
        num = in[st] - '0';
    }
    for (int i = st; i < end; i++)
    {
        if (in[i] == '[')
        {
            kk = 0;
            sum1++;
            if (k_index)
            {
                index1 = i;
                k_index = 0;
            }
        }
        if (kk)
            x += in[i];
        if (in[i] == ']')
        {
            sum2++;
        }
        if (kk == 0 && sum1 == sum2)
        {
            kk = 1;
            index2 = i;
            x += dfs(in, 1, index1+1, index2-1);
        }
    }

    if (sum1 == 0)
    {
        string ss;
        for (int i = st + 1; i <= end; i++)
            ss += in[i];
        for (int i = 0; i < num; i++)
        {
            x += ss;
        }
        return x;
    }
    return x;
}

int main()
{
    cin >> input;
    int len = input.length();
    cout << dfs(input, 0, 0, len);
    return 0;
}