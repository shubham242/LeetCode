class Solution {
public:
    int maxProfit(vector<int>& p) {
        if(p.size()<2)
            return 0;
        
        int sum=0;
        int smol=p[0];
        
        for(int i=1;i<p.size();i++)
        {
            if(p[i]<=p[i-1])
            {
                sum+=p[i-1]-smol;
                smol=p[i];
            }
        }
        if(p[p.size()-1]>p[p.size()-2])
            sum+=p[p.size()-1]-smol;
        
        return sum;
        
    }
};