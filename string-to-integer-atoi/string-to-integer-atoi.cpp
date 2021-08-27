class Solution
{
public:
    int myAtoi(string s)
    {
        long long int x = 0;
        bool neg = false;
        bool found = false;
        for (int i = 0; i < s.size(); i++)
        {
            if (x > INT_MAX)
            {

                if (neg)
                {
                    x = -x;
                    if (x < INT_MIN)
                        return INT_MIN;
                    else
                        return x;
                }
                else
                {
                    if (x > INT_MAX)
                        return INT_MAX;
                    else
                        return x;
                }
            }
            if (s[i] > 47 && s[i] < 58)
            {
                if (!found)
                    if (i > 0)
                        if (s[i - 1] == '-')
                            neg = true;
                x = x * 10 + s[i] - 48;
                found = true;
            }
            else
            {
                if (found)
                    break;
            }
            if (!found)
                if (s[i] == 32)
                    continue;
                else if (s[i] == '-' || s[i] == '+')
                {
                    if (!(s[i + 1] > 47 && s[i + 1] < 58))
                        return 0;
                }
                else
                    return 0;
        }
        if (neg)
        {
            x = -x;
            if (x < INT_MIN)
                return INT_MIN;
            else
                return x;
        }
        else
        {
            if (x > INT_MAX)
                return INT_MAX;
            else
                return x;
        }
    }
};