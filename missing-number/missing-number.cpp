static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int l=nums.size();
        int res=l*(l+1)/2;
        int sum=0;
        for(int i=0;i<l;i++)
            sum+=nums[i];
        return res-sum;
    }
};