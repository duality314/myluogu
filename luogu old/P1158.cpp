#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int dis(int x1, int x2, int y, int y2)
{
    return (x1 - x2) * (x1 - x2) + (y - y2) * (y - y2);
}

struct DD
{
    int l1, l2;
};
bool cmp(DD a, DD b)
{
    return a.l1 < b.l1;
}
DD dd[100005];

int x1, x2, yy, y2;
int N;

int main()
{
    cin >> x1 >> yy >> x2 >> y2;
    cin >> N;
    int x, y;
    for (int i = 1; i <= N; i++)
    {
        cin >> x >> y;
        dd[i].l1 = dis(x, x1, y, yy);
        dd[i].l2 = dis(x, x2, y, y2);
    }
    sort(dd + 1, dd + N + 1, cmp);
    int ans = dd[N].l1;
    int r2 = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        r2 = max(r2, dd[i + 1].l2);
        ans = min(ans, dd[i].l1 + r2);
    }
    cout<<ans;
    return 0;
}

/*using namespace std;
struct daodan
{
    int dis1, dis2;
} d[100005];                                             // 每个导弹分别到1,2的距离
bool cmp(daodan x, daodan y) { return x.dis1 < y.dis1; } // 将离1距离大的导弹放后面
int main()
{
    int n, x1, yy, x2, y2;
    cin >> x1 >> yy >> x2 >> y2;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int x, y;
        cin >> x >> y;                                         // 导弹的横纵坐标
        d[i].dis1 = (x - x1) * (x - x1) + (y - yy) * (y - yy); //
        d[i].dis2 = (x - x2) * (x - x2) + (y - y2) * (y - y2); // 到1,2距离
    }
    sort(d + 1, d + n + 1, cmp);     // 排序，将离1大的放后面
    int r2 = 0;                      // 2号半径平方用一个变量记录就行，如果小了就更新
    int ans = d[n].dis1;             // 全部导弹都用1拦截，即距离=拦截最远的
    for (int i = n - 1; i >= 1; --i) // 从后面开始一个个的给2拦截 ，1的半径减小
    {
        if (r2 < d[i + 1].dis2)
            r2 = d[i + 1].dis2;         // 如果新加入2的那个导弹距离比之前的都大，就更新
        ans = min(ans, d[i].dis1 + r2); // 答案为原答案和现在的最小值
    }
    cout << ans << endl;
    return 0;
}*/