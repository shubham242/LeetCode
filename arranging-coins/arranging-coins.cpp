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