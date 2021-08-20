class Solution {
public:
    int majorityElement(vector<int>& n) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n.size();i++)
        {
            mp[n[i]]++;
            if(mp[n[i]]>n.size()/2)
                return n[i];
        }
        return 0;
        
    }
};