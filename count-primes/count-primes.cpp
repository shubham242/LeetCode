class Solution {
public:
    int countPrimes(int n) {
        if(!n)
            return 0;
        bool prime[n];
        memset(prime, true, sizeof(prime));

        for (int p = 2; p * p <= n-1; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n-1; i += p)
                    prime[i] = false;
            }
        }
        int res=0;
        for (int p = 2; p <= n-1; p++)
            if (prime[p])
                res++;
        return res;
    }
};