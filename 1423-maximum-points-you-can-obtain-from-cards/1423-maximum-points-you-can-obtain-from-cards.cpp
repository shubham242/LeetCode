class Solution
{
public:
    int maxScore(vector<int> &c, int k)
    {
        int n = c.size();
        int sum = 0;
        int minSum = 0;
        int total = 0;

        for (int i = 0; i < n - k; i++)
            sum += c[i];
        minSum = sum;
        total = sum;
        for (int i = n - k; i < n; i++)
        {
            total += c[i];
            sum += c[i] - c[i - n + k];
            minSum = min(minSum, sum);
        }

        return total - minSum;
    }
};