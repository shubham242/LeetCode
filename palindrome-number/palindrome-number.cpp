class Solution {
public:
    bool isPalindrome(int x) {
        
        long int y=x,n=0;
        while(y>0)
        {
            n=n*10+y%10;
            y=y/10;
        }
        return x==n?true:false;
        
    }
};