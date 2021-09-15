class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& v) {
        int res=0;
        for (auto j = 1, max_i = v[0] - 1; j < v.size(); ++j, --max_i) {
        res = max(res, v[j] + max_i);
        max_i = max(max_i, v[j]);
        }
        return res;
    }
};