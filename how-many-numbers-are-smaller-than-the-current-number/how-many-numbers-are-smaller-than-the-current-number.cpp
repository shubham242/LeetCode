class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        vector<int> a=nums;
        sort(a.begin(),a.end());
        for(int i=0;i<nums.size();i++)
        {
            res.push_back(find(a.begin(),a.end(),nums[i])-a.begin());
        }
        return res;
    }
};