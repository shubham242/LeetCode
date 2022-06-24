class Solution
{
public:
    bool isPossible(vector<int> &t)
    {
        int n = t.size();
        if (n == 1)
            if (t[n - 1] != 1)
                return false;
            else
                return true;
        long sum = 0;
        for (auto i : t)
            sum += i;

        sort(t.begin(), t.end());
        while (t[n - 1] != 1)
        {
            int temp = t[n - 1];
            if (sum - t[n - 1] == 1)
                return true;
            if (t[n - 1] < sum - t[n - 1])
                return false;
            t[n - 1] = (t[n - 1] % (-t[n - 1] + sum));
            if (t[n - 1] < 1)
                return false;
            sum += t[n - 1] - temp;
            sort(t.begin(), t.end());
        }
        return true;
    }
};