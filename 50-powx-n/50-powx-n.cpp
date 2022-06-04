class Solution
{
public:
    double calc(double x, long n)
    {

        if (n == 0)
            return 1;
        else if (n % 2 == 0)
            return calc(x * x, n / 2);
        else
            return calc(x, n - 1) * x;
    }
    double myPow(double x, int n)
    {

        if (n < 0)
            return 1 / calc(x, -(long)n);
        return calc(x, n);
    }
};