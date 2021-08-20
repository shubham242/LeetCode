class Solution {
public:
    int majorityElement(vector<int>& n) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<n.size();i++)
        {
            mp[n[i]]++;
        }
        
        for(auto i : mp)
            if(i.second>n.size()/2)
                return i.first;
        return 0;
        
    }
};