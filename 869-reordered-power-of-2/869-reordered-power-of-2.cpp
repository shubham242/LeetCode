class Solution
{
public:
    bool reorderedPowerOf2(int n)
    {
        string s = to_string(n);
        sort(s.begin(), s.end());

        for (int i = 0; i < 32; i++)
        {
            string t = to_string(1 << i);
            sort(t.begin(), t.end());
            if (t == s)
                return true;
        }
        return false;
    }
};