class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            vector<int> a=nums;
            sort(a.begin(),a.end());
            auto it = find(a.begin(),a.end(),nums[i]);
            int x=it-a.begin();
            res.push_back(x);
        }
        return res;
    }
};