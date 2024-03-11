class Solution {
   public:
    string customSortString(string order, string s) {
        int size = s.size();
        int order_size = order.size();
        int hash[26] = {0};

        for (int i = 0; i < order_size; i++)
            hash[order[i] - 'a'] = i + 1;

        sort(s.begin(), s.end(), [&](char a, char b) {
            return hash[a - 'a'] < hash[b - 'a'];
        });

        return s;
    }
};