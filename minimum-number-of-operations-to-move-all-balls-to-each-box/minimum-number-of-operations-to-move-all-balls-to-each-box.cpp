class Solution {
public:
    vector<int> minOperations(string a) {
        vector<int> stepx,stepy,x;
        int sumx,sumy;
        sumx=a[0]=='1'?1:0;
        stepx.push_back(0);
        sumy=(a[a.size()-1])=='1'?1:0;
        stepy.push_back(0);
        int n=a.size();
        for(int i=1;i<a.size();i++)
        {
            stepx.push_back(sumx+stepx[i-1]);
            sumx=(sumx+(a[i]=='1'?1:0));
            
            stepy.push_back(sumy+stepy[i-1]);
            sumy=(sumy+(a[n-i-1]=='1'?1:0));
            
        }
        for(int i=0;i<n;i++)
            x.push_back(stepx[i]+stepy[n-i-1]);
        return x;
    }
};