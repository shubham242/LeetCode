class Solution {
   public:
    int findJudge(int n, vector<vector<int>> trust) {
        if (trust.size() == 0 && n == 1)
            return 1;
        vector<int> count(n + 1, 0);

        for (auto person : trust)
            count[person[0]]--, count[person[1]]++;

        for (int person = 0; person <= n; person++)
            if (count[person] == n - 1) return person;

        return -1;
    }
};