static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        for (int i = 0; i < min(strs[0].size(), strs[strs.size()-1].size()); i++)
        {
            if (strs[0][i] != strs[strs.size()-1][i])
                return strs[0].substr(0, i);
        }
        return strs[0];
    }
};