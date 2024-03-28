class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=size(nums), ans=0;
        unordered_map<int,int> mp;

        for(int l=0,r=0;r<n;r++){
            mp[nums[r]]++;

            if(mp[nums[r]]>k){
                while(nums[l]!=nums[r])
                    mp[nums[l++]]--;
                mp[nums[l++]]--;
            }

            ans=max(ans,r-l+1);
        }
        return ans;
    }
};