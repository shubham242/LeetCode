class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        else if(x==0)
            return true;
    int d=pow(10,int(log10(x)));
    while (x != 0) 
    {  
        if (x / d !=  x % 10)   
            return false; 
        x = (x % d) / 10; 
        d = d / 100; 
    } 
    return true;
}
};