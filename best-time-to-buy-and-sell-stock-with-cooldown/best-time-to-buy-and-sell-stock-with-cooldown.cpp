class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int b=INT_MIN;
        int s=0;
        int nb;
        int ns=0;
        
        for(auto p:prices)
        {   
            nb=b;
            b=max(ns-p,nb);
            ns=s;
            s=max(nb+p,ns);
        }
        
        return s;
    }
};