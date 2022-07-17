class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> res(n + 1, 0);
        for (int i = 1; i <= n; i++)
            res[i] = i % 2 == 0 ? res[i / 2] : res[i / 2] + 1;
        return res;
    }
};