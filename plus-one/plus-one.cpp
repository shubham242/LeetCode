class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        int i=d.size()-1;
        d[i]++;
        while(d[i]==10)
        {
            if(i>0)
            {
                d[i]=0;
                d[i-1]++; 
                i--;
            }
            else if(i==0)
            {
                d.push_back(0);
                d[i]=1;
            }
            
        }
        return d;
    }
};