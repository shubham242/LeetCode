class Solution {
public:
    int climbStairs(int n) {
        double phi = (sqrt(5) + 1) / 2;     
        return round(pow(phi, n+1) / sqrt(5));
    }
};