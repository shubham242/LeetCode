class Solution
{
public:
    int minPartitions(string n)
    {
        int ans = 0;

        for (auto i : n)
            if (i - '0' == 9)
                return 9;
            else
                ans = max(i - '0', ans);
        return ans;
    }
};