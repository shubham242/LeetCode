class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> _map;

        for(int i=0;i<n;i++){
            string temp = strs[i];
            sort(temp.begin(),temp.end());
            _map[temp].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto [key, value] : _map)
            res.push_back(value);

        return res;
    }
};