class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int h[amount+1];
        for(int i=0;i<amount+1;i++)
            h[i]=INT_MAX-1;
        h[0] = 0;
        for (int i = 0; i < amount+1; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (i >= coins[j])
                    h[i] = min(h[i], 1 + h[i - coins[j]]);
            }
        }
        return (h[amount] < INT_MAX-1 ) ? h[amount] : -1;
    }
};