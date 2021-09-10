class Solution {
public:
    int climbStairs(int n) { 
        return round(pow((sqrt(5) + 1) / 2, n+1) / sqrt(5));
    }
};