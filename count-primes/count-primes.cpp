class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
            return 0;
        vector<bool> prime(n + 1, true);
        int res = n - 2;
        for (int i = 2; i * i <= n-1; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= n-1; j += i)
                {
                    if (prime[j])
                        res--;
                    prime[j] = false;
                }
            }
        }
        return res;
    }
};