static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int dp(vector<int> &n, int l,int steps)
    {
        if (l == 0)
            return steps;
        for (int i = 0; i < l; i++)
        {
            if (i + n[i] >= l)
            {
                return dp(n,i,steps+1);
                break;
            }
        }
        return 0;
    }
    int jump(vector<int>& nums) {
        
        return dp(nums, nums.size() - 1,0);
    }
};