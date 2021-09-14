static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int currmax=0,resmax=0,numax=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            currmax+=nums[i];
            resmax=max(resmax,currmax);
            numax=max(numax,nums[i]);
            if(currmax<0)
                currmax=0;
        }
        if(resmax==0)
            return numax;
        else
        return resmax;
        
    }
};