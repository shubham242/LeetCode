class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0||n==INT_MIN)
            return false;
        if(n==1)
            return true;
        return !(n&(n-1));
    }
};