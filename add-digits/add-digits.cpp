static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int addDigits(int n) {
        if(n==0)
            return 0;
        if(n%9==0)
            return 9;
        else
            return n%9;
    }
};