class Solution {
public:
    int maxProfit(vector<int>& p) {
        
        int smol=INT_MAX;
        int big=INT_MIN;
        
        for(int i=0;i<p.size();i++)
        {
            smol=min(p[i],smol);
            big=max(p[i]-smol,big);
        }
        return big;
    }
};