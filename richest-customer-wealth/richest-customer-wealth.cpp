class Solution {
public:
    int maximumWealth(vector<vector<int>>& a) {
        int max=0;
        for(int i=0;i<a.size();i++)
        {
            int sum=accumulate(begin(a[i]),end(a[i]),0);
            if(sum>=max)
                max=sum;
        }
        return max;
    }
};