class Solution {
   public:
    int mod = 1e9 + 7, n;
    int dp[101][101][101];

    int power(long long x, unsigned int y, int p) {
        int res = 1;
        x = x % p;
        if (x == 0) return 0;
        while (y > 0) {
            if (y & 1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }

        return res;
    }

    int fun(int ind, int sum, int cnt, vector<int>& nums, int k) {
        if (ind >= n)
            if (sum == k)
                return power(2, n - cnt, mod) % mod;
            else
                return 0;

        if (dp[ind][sum][cnt] != -1)
            return dp[ind][sum][cnt];

        long sum1 = fun(ind + 1, sum, cnt, nums, k) % mod;
        long sum2 = 0;
        if (sum + nums[ind] <= k) sum2 = fun(ind + 1, sum + nums[ind], cnt + 1, nums, k) % mod;

        return dp[ind][sum][cnt] = (sum1 + sum2) % mod;
    }

    int sumOfPower(vector<int>& nums, int k) {
        n = nums.size();
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, 0, nums, k) % mod;
    }
};