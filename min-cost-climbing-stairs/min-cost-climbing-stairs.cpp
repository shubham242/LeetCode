static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    
    int minCostClimbingStairs(vector<int> &cost)
    {
        int l = cost.size();
        int f=cost[0];
        int s=cost[1];

        for (int i = 2; i < l; i++)
        {
            int curr = cost[i] + min(f, s);
            f=s;
            s=curr;
        }
        return min(f,s);
    }
};