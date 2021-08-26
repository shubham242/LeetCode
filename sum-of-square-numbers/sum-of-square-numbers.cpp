class Solution
{
public:
    bool isSquare(long int x)
    {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    bool judgeSquareSum(int c)
    {
        if (c == 0)
            return true;
        double x = sqrt(c);

        for (int i = 0; i < x; i++)
        {
            if (isSquare(c - i * i))
                return true;
        }
        return false;
    }
};