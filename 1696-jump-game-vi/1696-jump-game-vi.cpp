class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        int l = nums.size();
        deque<int> q{0};
        for (int i = 1; i < l; i++)
        {
            if (q.front() < i - k)
                q.pop_front();
            nums[i] += +nums[q.front()];
            while (!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();
            q.push_back(i);
        }
        return nums[l - 1];
    }
};