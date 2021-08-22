class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_map<int, int> mp;
        while (true)
        {
            if (mp[n] > 0)
                return false;
            mp[n]++;
            int y = n;
            n = 0;
            while (y > 0)
            {
                n += (y % 10) * (y % 10);
                y = y / 10;
            }
            if (n == 1)
                return true;
        }
    }
};