class Solution
{
public:
    using pii = pair<int, int>;
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        int res = INT_MIN;
        deque<pii> qu;
        for (auto &point : points)
        {
            int x = point[0], y = point[1];
            while (!qu.empty() && x - qu.front().second > k)
            {
                qu.pop_front();
            }
            if (!qu.empty())
            {
                res = max(res, x + y + qu.front().first);
            }
            while (!qu.empty() && y - x >= qu.back().first)
            {
                qu.pop_back();
            }
            qu.emplace_back(y - x, x);
        }
        return res;
    }
};
/*
给你一个数组 points 和一个整数 k 。数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序。也就是说 points[i] = [xi, yi] ，并且在 1 <= i < j <= points.length 的前提下， xi < xj 总成立。

请你找出 yi + yj + |xi - xj| 的 最大值，其中 |xi - xj| <= k 且 1 <= i < j <= points.length。

题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。

 */
/*




*/