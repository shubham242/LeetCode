class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;
        
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];
        for (int i = 1, j = n - 2; i < n; ++i, --j) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
            rightMax[j] = max(rightMax[j + 1], height[j]);
        }
        
        int totalWater = 0;
        for (int k = 1; k < n - 1; ++k) 
            totalWater += max(0, min(leftMax[k - 1], rightMax[k + 1]) - height[k]);

        
        return totalWater;
    }
};