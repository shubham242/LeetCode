class Solution {
   public:
    string minimizeStringValue(string s) {
        int n = s.size();
        int hash[26] = {0};
        string temp;

        for (int i = 0; i < n; i++)
            if (s[i] != '?')
                hash[s[i] - 'a']++;

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                int min_f = INT_MAX, min_index;
                for (int j = 0; j < 26; j++) {
                    if (hash[j] < min_f) {
                        min_index = j;
                        min_f = hash[j];
                    }
                }
                temp += 'a' + min_index;
                hash[min_index]++;
            }
        }
        sort(temp.begin(), temp.end());

        int j = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                s[i] = temp[j];
                j++;
            }
        }

        return s;
    }
};