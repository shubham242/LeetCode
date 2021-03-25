static const auto fast = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int arrangeCoins(long long int n) {
        long long int x=sqrt(n);
        while(x*(x+1)/2<=n)
            x++;
        x--;
        return x;
    }
};