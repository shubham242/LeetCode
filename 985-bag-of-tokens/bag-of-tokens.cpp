class Solution {
   public:
    int bagOfTokensScore(vector<int> &tokens, int power) {
        int n = tokens.size();
        sort(tokens.begin(), tokens.end());
        int ans = 0, maxAns = 0;

        for (int start = 0, end = n - 1; start <= end;) {
            if (tokens[start] <= power) {
                power -= tokens[start];
                start++;
                ans++;
            } else if (ans > 0) {
                power += tokens[end];
                end--;
                ans--;
            } else {
                break;
            }
            maxAns = max(maxAns, ans);
        }

        return maxAns;
    }
};