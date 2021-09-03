static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    vector<int> decode(vector<int>& e, int first) {
        e.insert(e.begin(),first);
        for(int i=1;i<e.size();i++)
            e[i]=e[i]^e[i-1];
        return e;
    }
};