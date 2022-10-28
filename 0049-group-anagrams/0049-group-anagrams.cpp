class Solution {
public:
    bool isAnagram(string a, string b)
    {
        if (a.length() != b.length()) {
            return false;
        }
        unordered_map<char, int> Map;
        for (int i = 0; i < a.length(); i++) {
            Map[a[i]]++;
        }
        for (int i = 0; i < b.length(); i++) {
            if (Map.find(b[i]) != Map.end()) {
                Map[b[i]] -= 1;
            }
            else {
                return false;
            }
        }
        for (auto items : Map) {
            if (items.second != 0) {
                return false;
            }
        }
        return true;
    }
    
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