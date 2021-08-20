class Solution {
public:
    int titleToNumber(string c) {
        
        long int res=0;
        for(int i=0;i<c.size();i++)
            res=res*26+c[i]-64;
        return res;
    }
};