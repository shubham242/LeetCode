class Solution
{
public:
    bool isPossible(vector<int> &t)
    {
        int n = t.size();
        long sum = 0;
        for (auto i : t)
            sum += i;

        sort(t.begin(), t.end());
        while (t[n - 1] != 1)
        {
            sum -= t[n - 1];
            if (sum == 0 || sum >= t[n - 1])
                return false;
            t[n - 1] = t[n - 1] % sum;
            if (sum != 1 && t[n - 1] == 0)
                return false;
            sum += t[n - 1];
            sort(t.begin(), t.end());
        }
        return true;
    }
};