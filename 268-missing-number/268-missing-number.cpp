class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int s=0;
        int l= nums.size();
        for(int i=0;i<l;i++)
            s+=nums[i];
        
        return (l*(l+1))/2-s;
    }
};