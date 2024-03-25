class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        for(int num : nums){
            int idx = abs(num);
            if(nums[idx-1]<0)
                res.push_back(idx);
            nums[idx-1]=-nums[idx-1];
        }
        return res;
    }
};