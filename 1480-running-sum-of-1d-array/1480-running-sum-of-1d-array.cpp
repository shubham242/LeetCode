class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int l=nums.size();
        for(int i=1;i<l;i++)
            nums[i]+=nums[i-1];
        return nums;
    }
};