class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set;
        int ans = 0;
        for (auto i : nums)
            set.insert(i);

        for (auto i : nums)
        {
            if (!set.count(i - 1))
            {
                int count = 1;
                for (int j = 1; set.count(i + j); i++)
                    count++;
                ans = max(ans, count);
            }
        }
        return ans;
    }
};