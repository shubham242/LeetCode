class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        double N = n + m - 2;
        double C = max(m - 1, n - 1);
        double res = 1;
        for (double i = 1; i <= C; i++)
            res *= (N - i + 1) / i;
        return (int)round(res);
    }
};