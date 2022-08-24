class Solution {
public:
    bool isPowerOfThree(int x) {
        
        if(x==0)
            return false;
        if(x==1)
            return true;
        if(x%3==0)
            return isPowerOfThree(x/3);
        return false;
    }
};