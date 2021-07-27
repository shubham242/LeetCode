static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start=0 ,end=0;
        int sum=0;
        int  n=nums.size();
        int min_length=n+1;
        while(end<n)
        {
            while(sum<target && end<n)
            {
                sum=sum+nums[end];
                end++;
            }
            
            while(sum>=target && start<n)
            {
                min_length=min(min_length,end-start);
                sum=sum-nums[start];
                start++;
            }
        }
        if(min_length!=nums.size()+1)
        return min_length;
        else
            return 0;
        
    }
};