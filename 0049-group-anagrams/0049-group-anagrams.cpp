class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string,vector<string>> Map;
        
        for(int i=0;i<strs.size();i++)
        {
            string s=strs[i];
            sort(strs[i].begin(),strs[i].end());
            Map[strs[i]].push_back(s);
        }
        
        vector<vector<string>> res;
        
        for(auto i: Map)
        {
            vector<string> temp;
            for(int j=0;j<i.second.size();j++)
                temp.push_back(i.second[j]);
            res.push_back(temp);
        }
        
        return res;
    }
};