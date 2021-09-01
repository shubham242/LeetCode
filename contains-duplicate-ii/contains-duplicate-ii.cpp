static const auto fast = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> n, int k)
    {
        int l = n.size();
        pair<int, int> arr[l];
        for (int i = 0; i < l; i++)
        {
            arr[i] = make_pair(n[i], i);
        }
        sort(arr, arr + l);
        for (int i = 0; i < l-1; i++)
        {
            if (arr[i].first == arr[i + 1].first && abs(arr[i].second - arr[i + 1].second) <= k)
                return true;
        }
        return false;
    }
};