class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        int dp1 = 1;
        int dp2 = 2;

        for (int i = 3; i <= n; i++)
        {
            int dp = dp1 + dp2;
            dp1 = dp2;
            dp2 = dp;
        }
        return dp2;
    }
};