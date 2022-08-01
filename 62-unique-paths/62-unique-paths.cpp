class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        m--;
        n--;
        if (m < n)
            swap(m, n);

        double res = 1;
        for (double i = m + 1; i <= m + n; i++)
            res *= i / (i - (double)m);
        return round(res);
    }
};