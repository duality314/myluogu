class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int len = nums.size();
        int left = 0, right = len - 1, middle;
        while (left <= right)
        {
            middle = left + (right - left) / 2;
            if (nums[middle] < target)
                left = middle + 1;
            else if (nums[middle] > target)
                right = middle - 1;
            else
                return middle;
        }
        return left + 1;
    }
};