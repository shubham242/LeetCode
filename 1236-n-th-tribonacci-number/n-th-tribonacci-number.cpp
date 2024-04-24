class Solution {
public:
    int tribonacci(int n) {
        if(n<2)
            return n;
        else if(n==2)
            return 1;
        
        int a1=0,a2=1,a3=1, res;
        for(int i=0;i<n-2;i++)
        {
            res=a1+a2+a3;
            a1=a2;
            a2=a3;
            a3=res;
        }
        return res;
    }
};