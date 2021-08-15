class Solution {
public:
    int climbStairs(int n) {
    double phi = (pow(5, 0.5) + 1) / 2;
    int fibo = round(pow(phi, n + 1) / pow(5, 0.5));

    return fibo;
    }
};