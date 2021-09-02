class Solution {
public:
    bool wordPattern(string pattern, string s)
    {
        vector<string> data;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                data.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }
        data.push_back(temp);
        unordered_map<int, string> mp;
        unordered_map<string, int> mp2;
        if (data.size() != pattern.size())
            return false;

        for (int i = 0; i < data.size(); i++)
        {
            if (mp[pattern[i] - 'a'] == "")
                mp[pattern[i] - 'a'] = data[i];
            else if (mp[pattern[i] - 'a'] != data[i])
                return false;
            
            if(mp2[data[i]]==0)
                mp2[data[i]]=pattern[i]-'a'+1;
            else if (mp2[data[i]]!=pattern[i]-'a'+1)
                return false;
        }
        return true;
    }
};