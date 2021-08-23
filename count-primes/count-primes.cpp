
class Solution
{
public:
    int countPrimes(int n)
    {
        if (n == 0 || n == 1)
            return 0;
        bool prime[n];
        int res = n - 2;
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n - 1; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n - 1; i += p)
                {
                    if (prime[i])
                        res--;
                    prime[i] = false;
                }
            }
        }
        return res;
    }
};