class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x==0)
            return true;
    int divisor=pow(10,int(log10(x)));
    while (x != 0) 
    { 
        int leading = x / divisor;  
        int trailing = x % 10; 
   
        if (leading != trailing)   
            return false; 
 
        x = (x % divisor) / 10; 
  
        divisor = divisor / 100; 
    } 
    return true;
}
};