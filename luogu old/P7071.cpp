#include <iostream>
#include <cstdio>

using namespace std;

int a[40];
bool use[40];
int result[40];
int index;
int n;
// int sum;
void dfs(int sum)
{
    if (sum == n)
    {
        //倒序输出
        for (int j = 0; j < index; j++)
        {
            cout << result[j] << " ";
        }
        exit(0);
    }
    else if (sum > n)
    {
        return;
    }
    else
    {
        for (int i = 24;i>0; i--)
        {
            if (!use[i])
            {
                use[i] = 1;
                sum += a[i];
                result[index] = a[i];
                index++;
                dfs(sum);
                sum -= a[i];
                index--;
                use[i] = 0;
            }
        }
    }
}
int main()
{
    int i = 1;
    int temp=0;
    while (temp < 1E7)
    {
        temp = 1 << i;
        a[i] = temp;
        i++;
    }
    cin >> n;
    dfs(0);
    cout << "-1";
    return 0;
}