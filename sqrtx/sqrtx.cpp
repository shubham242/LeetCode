  
static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    int mySqrt(int x) {
        long int s=0;
        long int e=x;
        while(s<=e)
        {
            long int m=(e+s)/2;
            if ((m * m <= x)&& ((m + 1) * (m + 1) > x))
            return m;
            if(m*m<x)
                s=m+1;
            else
                e=m-1;
                
        }
        return s;
    }
};