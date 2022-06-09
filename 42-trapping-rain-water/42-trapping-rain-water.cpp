class Solution
{
public:
    int trap(vector<int> &h)
    {
        int s = 0;
        int e = h.size() - 1;
        int hs = 0, he = 0;
        int sum = 0;
        while (s <= e)
        {
            hs = max(hs, h[s]);
            he = max(he, h[e]);

            if (hs <= he)
            {
                sum += hs;
                s++;
            }
            else if (he < hs)
            {
                sum += he;
                e--;
            }
            else
            {
                sum += hs;
                s++;
                if (s < e)
                {
                    sum += he;
                    e--;
                }
            }
        }
        int total = 0;
        for (auto i : h)
            total += i;
        return sum - total;
    }
};