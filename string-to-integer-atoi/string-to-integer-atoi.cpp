class Solution
{
public:
    int myAtoi(string s)
    {
        long int x = 0;
        int neg = 1;
        bool f = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (!f && s[i] == ' ')
                continue;
            else if (!f && (s[i] == '-' || s[i] == '+'))
            {
                neg = s[i] == '-' ? -1 : 1;
                if (!(s[i + 1] > 47 && s[i + 1] < 58))
                    return 0;
            }
            else if (s[i] > 47 && s[i] < 58)
            {
                f = true;
                x = x * 10 + s[i] - '0';
                if (x * neg > INT_MAX)
                    return INT_MAX;
                if (x * neg < INT_MIN)
                    return INT_MIN;
            }
            else
                return x * neg;
        }
        return x * neg;
    }
};