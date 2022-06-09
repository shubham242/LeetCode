class Solution
{
public:
    int trap(vector<int> &h)
    {
        int l = h.size();
        int sum = 0;

        int maxH = 0;

        for (int i = 0; i < l; i++)
        {
            maxH = 0;
            if (h[i] > 0)
                for (int j = i - 1; j >= 0; j--)
                    if (h[j] > maxH)
                    {
                        sum += (i - j - 1) * (min(h[j], h[i]) - maxH);
                        if (h[j] >= h[i])
                            break;
                        maxH = h[j];
                    }
        }

        return sum;
    }
};