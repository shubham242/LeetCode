class Solution {
   public:
    string frequencySort(string s) {
        int n = s.size();
        vector<pair<int, char>> freq(128);
        string ans = "";

        for (char c : s) {
            freq[c].second = c;
            freq[c].first++;
        }

        sort(freq.begin(), freq.end(), greater<pair<int, char>>());
        for (auto it : freq)
            ans += string(it.first, it.second);

        return ans;
    }
};