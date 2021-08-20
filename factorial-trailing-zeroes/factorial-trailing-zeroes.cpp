class Solution {
public:
    int trailingZeroes(int n) {
        long int r=5,ans=0;
        while(r<=n)
        {
            int y=r;
            while(y%5==0)
            {
                y=y/5;
                ans++;
            }
            r+=5;
        }
        return ans;
    }
};