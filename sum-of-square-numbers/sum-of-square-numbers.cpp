class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        long int e = sqrt(c);
        long int s = 0;
        while (s <= e)
        {
            if (c == s * s + e * e)
                return true;
            else if (c < s * s + e * e)
                e--;
            else
                s++;
        }
        return false;
    }
};