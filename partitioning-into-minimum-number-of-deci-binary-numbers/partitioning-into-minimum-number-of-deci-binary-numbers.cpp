static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
class Solution {
public:
    int minPartitions(string n) {
        return *max_element(n.begin(),n.end())-'0';
    }
};