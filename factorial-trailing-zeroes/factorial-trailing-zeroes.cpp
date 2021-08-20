class Solution {
public:
    int trailingZeroes(int n) {
        long int r=5,ans=0;
        while(r<=n)
        {
            ans+=n/r;
            r*=5;
        }
        return ans;
    }
};