class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prod=INT_MIN;
        int l=nums.size();
        for(int i=0;i<l;i++)
        {
            int temp=nums[i];
            prod=max(prod,temp);
            for(int j=i+1;j<l;j++)
            {
                temp*=nums[j];
                prod=max(prod,temp);
            }
        }
        return prod;
    }
};