class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int b=INT_MIN;
        int s=0;
        int c=0;
        
        for(auto p:prices)
        {
            int nb=b;
            int ns=s;
            int nc=c;
            
            b=max(nc-p,nb);
            s=max(nb+p,ns);
            c=max(nc,ns);
        }
        
        return s;
    }
};