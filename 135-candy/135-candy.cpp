class Solution
{
public:
    int candy(vector<int> &r)
    {
        int l = r.size();
        if (l == 1)
            return 1;
        vector<int> res(l, -1);
        int j = 0;
        if (r[0] <= r[1])
            res[0] = 1;
        while (j < l - 1 && r[j + 1] > r[j])
        {
            res[j + 1] = res[j] + 1;
            j++;
        }

        for (int i = 1; i < l; i++)
        {
            if (r[i] <= r[i - 1])
            {
                if (res[i] == -1)
                    res[i] = 1;
            }
            if (r[i] > r[i - 1])
            {
                res[i] = res[i - 1] + 1;
            }
        }
        j = l - 1;
        if (r[l - 1] <= r[l - 2])
            res[l - 1] = 1;
        while (j > 0 && r[j - 1] > r[j])
        {
            res[j - 1] = max(res[j - 1], res[j] + 1);
            j--;
        }

        for (int i = l - 2; i >= 0; i--)
        {
            if (r[i] <= r[i + 1])
            {
                if (res[i] == -1)
                    res[i] = 1;
            }
            if (r[i] > r[i + 1])
            {
                res[i] = max(res[i], res[i + 1] + 1);
            }
        }

        int sum = 0;
        for (int i : res)
            sum += i;
        return sum;
    }
};