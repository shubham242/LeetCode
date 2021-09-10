static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int climbStairs(int n) { 
        return round(pow((sqrt(5) + 1) / 2, n+1) / sqrt(5));
    }
};