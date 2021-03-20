class Solution {
public:
    int arrangeCoins(long long int n) {
        if(n==0)
            return 0;
        else if(n==1)
            return 1;
        if(n==2)
            return 1;
        long long int x=sqrt(n);
        while(x*(x+1)/2<=n)
            x++;
        x--;
        return x;
    }
};