class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        for(int i=0;i<32;i++)
        {
            if(n%2!=0)
                res++;
            n=n>>1;
        }
        return res;
    }
};