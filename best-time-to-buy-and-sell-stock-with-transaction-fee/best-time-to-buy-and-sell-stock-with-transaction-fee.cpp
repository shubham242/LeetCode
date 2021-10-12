class Solution
{
public:
    int maxProfit(vector<int> &p, int fee)
    {
        int n=p.size();
        int cash = 0, hold = -p[0];
        for (int i = 1; i < n; i++) {
            cash = max(cash, hold + p[i]-fee);
            hold = max(hold, cash - p[i]);
        }
        return cash;
    }
};