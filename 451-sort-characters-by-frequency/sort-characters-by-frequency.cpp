class Solution {
   public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        vector<pair<int, char>> v;
        string ans = "";

        for (char c : s)
            freq[c]++;

        for (auto it : freq)
            v.push_back({it.second, it.first});

        sort(v.begin(), v.end(), greater<pair<int, char>>());
        for (auto it : v)
            ans += string(it.first, it.second);

        return ans;
    }
};