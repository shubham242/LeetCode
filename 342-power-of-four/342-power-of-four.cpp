class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n<=0)
            return false;
        
        return ((int)(log2(n))%2)==0&&pow(2,(int)(log2(n)))==n;
    }
};